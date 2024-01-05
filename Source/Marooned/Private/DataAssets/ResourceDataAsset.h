// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include <GameplayTagContainer.h>
#include "ResourceDataAsset.generated.h"

class UItemDataAsset;

/**
 * 
 */
UCLASS()
class UResourceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AMUResourceActor> ResouceActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UItemDataAsset* DroppedItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbilitySystem")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbilitySystem")
	float StartingHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbilitySystem")
	float ToolStrength;
};
