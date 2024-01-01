// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/HierarchicalInstancedStaticMeshComponent.h>
#include <AbilitySystemInterface.h>
#include "MUResourceChunk.generated.h"

class UMUResourceInstanceComponent;
class UMaroonedAbilitySystemComponent;
class UMUResourceAttributeSet;
class UResourceDataAsset;
struct FOnAttributeChangeData;
struct FGameplayEffectModCallbackData;

UCLASS()
class AMUResourceChunk : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	

	AMUResourceChunk();

	// BP_WorldItem needs to be spawned from Blueprint since it is defined in blueprint
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "ResourceDestroyed"))
	void RecieveResourceDestroyed(FTransform Transform);

	// Used to Broadcast an Event Dispatcher in Blueprint
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "ResourceHealthChanged"))
	void RecieveResourceHealthChanged(UMUResourceInstanceComponent* Component, int32 InstanceIndex);

	UFUNCTION(BlueprintCallable)
	void SpawnResourceGroup(int32 ComponentIndex, UResourceDataAsset* ResourceDataAsset, const TArray<FTransform>& Transforms);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:

	// Called on Server in response to damage applied by an effect
	void OnTakeDamage(const FGameplayEffectModCallbackData& Data);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastTakeDamage(int32 InstanceIndex, int32 ComponentIndex, float Damage, FHitResult HitResult);
	

protected:

	const int32 NumResourceComponents{ 4 };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<UMUResourceInstanceComponent*> ResourceInstanceComponents;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UMaroonedAbilitySystemComponent* AbilitySystemComponent{};

	UPROPERTY(Transient)
	UMUResourceAttributeSet* AttributeSet{};
};
