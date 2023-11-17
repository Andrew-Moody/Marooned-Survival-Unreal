// Fill out your copyright notice in the Description page of Project Settings.


#include "MaroonedAssetManager.h"
#include <AbilitySystemGlobals.h>

void UMaroonedAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();

	UE_LOG(LogTemp, Warning, TEXT("StartInitalLoading Called"));
}
