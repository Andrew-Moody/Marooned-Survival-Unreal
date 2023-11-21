// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MUGameplayAbility.generated.h"

struct FGameplayAbilityActorInfo;

/**
 * 
 */
UCLASS()
class UMUGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	bool bActivateOnGranted{ false };

	UPROPERTY(EditDefaultsOnly)
	bool bAllowRemoteActivation{ false };

protected:

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
