// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemTypes.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FMUItemStack
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FPrimaryAssetId ItemAssetId{};

	UPROPERTY(BlueprintReadWrite)
	int32 Count{};
};
