// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "MaroonedAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class MAROONED_API UMaroonedAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:

	void StartInitialLoading() override;
};
