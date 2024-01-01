// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MUResourceInstanceData.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "MUResourceInstanceComponent.generated.h"

class UResourceDataAsset;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMUResourceInstanceComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void Populate(const TArray<FTransform>& Transforms);

	UFUNCTION(BlueprintCallable)
	void ShowInstance(int32 InstanceIndex);

	UFUNCTION(BlueprintCallable)
	void HideInstance(int32 InstanceIndex);

	UFUNCTION(BlueprintCallable)
	void CullInstance(int32 InstanceIndex, const FTransform& CullTransform);

	UFUNCTION(BlueprintCallable)
	float GetHealth(int32 InstanceIndex);

	UFUNCTION(BlueprintCallable)
	FTransform GetTransform(int32 InstanceIndex);

	void TakeDamage(int32 InstanceIndex, float Damage, const FHitResult& HitResult);

	void FinishHitFX(int32 InstanceIndex);

	void FinishDeathFX(int32 InstanceIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ComponentIndex{ -1 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UResourceDataAsset* DataAsset;

protected:
	
	TArray<FMUResourceInstanceData> Instances{};
};
