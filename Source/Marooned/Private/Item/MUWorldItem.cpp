// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/MUWorldItem.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "Item/MUItemSubsystem.h"
#include "DataAssets/ItemDataAsset.h"

// Sets default values
AMUWorldItem::AMUWorldItem()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	//SetReplicateMovement(true);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SetRootComponent(StaticMeshComponent);

	StaticMeshComponent->SetCollisionProfileName(FName("Collectible"));

	StaticMeshComponent->SetSimulatePhysics(true);
}

void AMUWorldItem::SetItemStack(const FMUItemStack& NewItemStack)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to SetItemStack without authority"));
		return;
	}

	FMUItemStack OldItemStack = ItemStack;
	ItemStack = NewItemStack;

	// Update visuals on server (OnRep Doesn't get called on server)
	SetupItemMesh(OldItemStack);
}

void AMUWorldItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(AMUWorldItem, ItemStack, COND_None, REPNOTIFY_Always);
}

void AMUWorldItem::OnRep_ItemStack(const FMUItemStack& OldValue)
{
	//FString Auth = HasAuthority() ? "With Authority" : "Without Authority";
	//UE_LOG(LogTemp, Warning, TEXT("OnRep_ItemStack %s"), *Auth);

	SetupItemMesh(OldValue);
}

void AMUWorldItem::SetupItemMesh(const FMUItemStack& OldValue)
{
	//FString Auth = HasAuthority() ? "With Authority" : "Without Authority";
	//UE_LOG(LogTemp, Warning, TEXT("SetMesh %s"), *Auth);

	UMUItemSubsystem* ItemSubsystem = UMUItemSubsystem::Get(GetWorld());

	if (!ItemSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("ItemSubsystem not found"));
		return;
	}

	UItemDataAsset* ItemAsset = ItemSubsystem->GetItemAssetFromId(ItemStack.ItemAssetId);

	if (!ItemAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("ItemAsset not found"));
		return;
	}

	if (!ItemAsset->Mesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("Mesh not found"));
		return;
	}

	StaticMeshComponent->SetStaticMesh(ItemAsset->Mesh);
}

