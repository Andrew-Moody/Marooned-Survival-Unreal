// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGen/MUResourceInstanceComponent.h"
#include "DataAssets/ResourceDataAsset.h"
#include "MUResourceChunk.h"
#include "MUResourceActor.h"
#include "Item/ItemTypes.h"
#include "Item/MUItemSubsystem.h"
#include "DataAssets/ItemDataAsset.h"
#include "Timer.h"

void UMUResourceInstanceComponent::Populate(const TArray<FTransform>& Transforms)
{
	if (!DataAsset)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Missing DataAsset"));
		return;
	}
	
	SetStaticMesh(DataAsset->StaticMesh);

	Timer Timer{};

	AddInstances(Transforms, false, true);

	const int32 Num{ Transforms.Num() };

	Instances.Reset(Num);

	for (int32 i = 0; i < Num; ++i)
	{
		SetCustomDataValue(i, 0, 1.0f, false);

		Instances.Push({ DataAsset->StartingHealth });
	}

	double Time = Timer.GetElapsedTimeSec();

	UE_LOG(LogTemp, Warning, TEXT("Added %i Instances in %f seconds"), Num, Time);
}

void UMUResourceInstanceComponent::ShowInstance(int32 Index)
{
	SetCustomDataValue(Index, 0, 1.0f, true);
}

void UMUResourceInstanceComponent::HideInstance(int32 Index)
{
	SetCustomDataValue(Index, 0, 0.0f, true);
}

void UMUResourceInstanceComponent::CullInstance(int32 Index, const FTransform& CullTransform)
{
	UpdateInstanceTransform(Index, CullTransform, true, true, true);
}

float UMUResourceInstanceComponent::GetHealth(int32 InstanceIndex)
{
    return Instances[InstanceIndex].Health;
}

FTransform UMUResourceInstanceComponent::GetTransform(int32 InstanceIndex)
{
	FTransform Transform;

	GetInstanceTransform(InstanceIndex, Transform);

	return Transform;
}

void UMUResourceInstanceComponent::TakeDamage(int32 InstanceIndex, float Damage, const FHitResult& HitResult)
{
	FString msg = FString::Printf(TEXT("TakeDamage Index: %i, Damage: %f"), InstanceIndex, Damage);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, msg);

	// Replace the instance with a local actor to perform FX

	FTransform SpawnTransform{};
	GetInstanceTransform(InstanceIndex, SpawnTransform);

	FActorSpawnParameters SpawnInfo{};
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AMUResourceActor* ResourceActor = GetWorld()->SpawnActor<AMUResourceActor>(DataAsset->ResouceActor, SpawnTransform, SpawnInfo);

	if (!ResourceActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Failed to spawn ResourceActor"));
		return;
	}

	HideInstance(InstanceIndex);


	// Deduct damage from health and start FX

	float Health = Instances[InstanceIndex].Health;

	Health -= Damage;

	if (Health <= 0.0f)
	{
		Health = 0.0f;

		ResourceActor->OnFinishFX.BindUObject(this, &UMUResourceInstanceComponent::FinishDeathFX, InstanceIndex);
		ResourceActor->StartDeathFX(HitResult);
	}
	else
	{
		ResourceActor->OnFinishFX.BindUObject(this, &UMUResourceInstanceComponent::FinishHitFX, InstanceIndex);
		ResourceActor->StartHitFX(HitResult);
	}

	Instances[InstanceIndex].Health = Health;

	AMUResourceChunk* Chunk = Cast<AMUResourceChunk>(GetOwner());

	if (Chunk)
	{
		Chunk->RecieveResourceHealthChanged(this, InstanceIndex);
	}
}

void UMUResourceInstanceComponent::FinishHitFX(int32 InstanceIndex)
{
	ShowInstance(InstanceIndex);
}

void UMUResourceInstanceComponent::FinishDeathFX(int32 InstanceIndex)
{
	// Spawn an item if on the Server
	if (GetOwnerRole() == ENetRole::ROLE_Authority)
	{
		FTransform Transform{};

		GetInstanceTransform(InstanceIndex, Transform);

		Transform.AddToTranslation({ 0.0f, 0.0f, 100.0f });

		FPrimaryAssetId AssetId = DataAsset->DroppedItem->GetPrimaryAssetId();

		FMUItemStack ItemStack{ AssetId, 1 };

		UMUItemSubsystem::Get(GetWorld())->SpawnWorldItem(ItemStack, Transform);
	}

	// Show where the instance was moved to for debugging
	ShowInstance(InstanceIndex);

	CullInstance(InstanceIndex, FTransform(FVector(0.0f, 0.0f, 1000.0f)));
}
