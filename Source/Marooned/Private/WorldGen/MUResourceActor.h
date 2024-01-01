// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MUResourceActor.generated.h"

class UMUResourceInstanceComponent;

DECLARE_DELEGATE(FOnFinishFXDelegate);

UCLASS()
class AMUResourceActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AMUResourceActor();

	void StartHitFX(const FHitResult& HitResult);

	void StartDeathFX(const FHitResult& HitResult);

	FOnFinishFXDelegate OnFinishFX;

protected:	
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "StartHitFX"))
	void StartHitFX_BPImpl(const FHitResult& HitResult);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "StartDeathFX"))
	void StartDeathFX_BPImpl(const FHitResult& HitResult);

	UFUNCTION(BlueprintCallable)
	void FinishFX();
};
