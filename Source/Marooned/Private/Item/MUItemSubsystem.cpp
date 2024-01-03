// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/MUItemSubsystem.h"
#include "Item/ItemTypes.h"
#include "Item/MUWorldItem.h"
#include "Engine/AssetManager.h"
#include "DataAssets/ItemDataAsset.h"
#include "Kismet/GameplayStatics.h"

UItemDataAsset* UMUItemSubsystem::GetItemAssetFromId(const FPrimaryAssetId& PrimaryAssetId)
{
	auto iter = LoadedItemAssets.Find(PrimaryAssetId);

	if (iter)
	{
		return *iter;
	}

	return nullptr;
}

AMUWorldItem* UMUItemSubsystem::SpawnWorldItem(const FMUItemStack& ItemStack, const FTransform& Transform)
{
	FActorSpawnParameters SpawnParams{};

	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AMUWorldItem* WorldItem = GetWorld()->SpawnActor<AMUWorldItem>(AMUWorldItem::StaticClass(), Transform, SpawnParams);
	
	WorldItem->SetItemStack(ItemStack);

	return WorldItem;
}

void UMUItemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UAssetManager* manager = UAssetManager::GetIfValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Start Asset Load"));

		OnItemAssetsLoaded();

		/*TArray<FPrimaryAssetId> AssetIdList;

		manager->GetPrimaryAssetIdList("ItemDataAsset", AssetIdList);

		UE_LOG(LogTemp, Warning, TEXT("Found %i AssetId's"), AssetIdList.Num());

		FStreamableDelegate Delegate = FStreamableDelegate::CreateUObject(this, &UMUItemSubsystem::OnItemAssetsLoaded);

		manager->LoadPrimaryAssets(AssetIdList, TArray<FName>(), Delegate);*/

		//UAssetManager::Get().LoadPrimaryAssetsWithType
	}
}

void UMUItemSubsystem::OnItemAssetsLoaded()
{
	UE_LOG(LogTemp, Warning, TEXT("Finish Asset Load"));

	if (UAssetManager* manager = UAssetManager::GetIfValid())
	{
		TArray<FAssetData> AssetDataList;

		manager->GetPrimaryAssetDataList("ItemDataAsset", AssetDataList);

		UE_LOG(LogTemp, Warning, TEXT("Found %i DataAssets"), AssetDataList.Num());

		for (auto& Asset : AssetDataList)
		{
			UItemDataAsset* ItemAsset = Cast<UItemDataAsset>(Asset.GetAsset());

			if (ItemAsset)
			{
				LoadedItemAssets.Add(ItemAsset->GetPrimaryAssetId(), ItemAsset);

				UE_LOG(LogTemp, Warning, TEXT("Found %s"), *(ItemAsset->GetPrimaryAssetId().ToString()));
			}
		}
	}
}

UMUItemSubsystem* UMUItemSubsystem::Get(const UWorld* World)
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(World);

	if (!GameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameInstance not found"));
		return nullptr;
	}

	UMUItemSubsystem* ItemSubsystem = GameInstance->GetSubsystem<UMUItemSubsystem>();

	if (!ItemSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("ItemSubsystem not found"));
		return nullptr;
	}

	return ItemSubsystem;
}
