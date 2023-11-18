// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include <AbilitySystemInterface.h>
#include "MaroonedGASPlayerState.generated.h"

class UMaroonedAbilitySystemComponent;
class UMaroonedAttributeSet;
struct FOnAttributeChangeData;

/**
 * 
 */
UCLASS()
class AMaroonedGASPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:

	AMaroonedGASPlayerState();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:

	virtual void HealthChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "HealthChanged"))
	void RecieveHealthChanged(float NewHealth, float OldHealth);

	UPROPERTY()
	UMaroonedAbilitySystemComponent* AbilitySystemComponent{ nullptr };

	UPROPERTY(Transient)
	UMaroonedAttributeSet* AttributeSet{ nullptr };
};
