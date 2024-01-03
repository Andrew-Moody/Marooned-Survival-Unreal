// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MUItemSubsystem.generated.h"

class UItemDataAsset;
class AMUWorldItem;

/**
 * 
 */
UCLASS()
class UMUItemSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	UItemDataAsset* GetItemAssetFromId(const FPrimaryAssetId& PrimaryAssetId);
	
	UFUNCTION(BlueprintCallable)
	AMUWorldItem* SpawnWorldItem(const FMUItemStack& ItemStack, const FTransform& Transform);

	// Blueprints should use built in subsystem access
	static UMUItemSubsystem* Get(const UWorld* World);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:

	void OnItemAssetsLoaded();

	TMap<FPrimaryAssetId, UItemDataAsset*> LoadedItemAssets;
};
