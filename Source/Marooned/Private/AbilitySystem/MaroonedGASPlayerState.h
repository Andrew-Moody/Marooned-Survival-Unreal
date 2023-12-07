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

	UPROPERTY(VisibleAnywhere)
	UMaroonedAbilitySystemComponent* AbilitySystemComponent{ nullptr };

	UPROPERTY(Transient, VisibleAnywhere)
	UMaroonedAttributeSet* AttributeSet{ nullptr };

	// These are used as callbacks for when an attribute changes
	// Currently all logic is handled in blueprint but still need these functions
	// to forward data since FOnAttributeChangeData can't be used directly
	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	void ManaChanged(const FOnAttributeChangeData& Data);
	void MaxManaChanged(const FOnAttributeChangeData& Data);
	void StaminaChanged(const FOnAttributeChangeData& Data);
	void MaxStaminaChanged(const FOnAttributeChangeData& Data);
	void HungerChanged(const FOnAttributeChangeData& Data);
	void MaxHungerChanged(const FOnAttributeChangeData& Data);

	void SpeedChanged(const FOnAttributeChangeData& Data);
	void MeleeStrengthChanged(const FOnAttributeChangeData& Data);
	void MagicStrengthChanged(const FOnAttributeChangeData& Data);
	void ToolStrengthChanged(const FOnAttributeChangeData& Data);
	void DefenseChanged(const FOnAttributeChangeData& Data);
	void ArmorChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "HealthChanged"))
	void RecieveHealthChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MaxHealthChanged"))
	void RecieveMaxHealthChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "ManaChanged"))
	void RecieveManaChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MaxManaChanged"))
	void RecieveMaxManaChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "StaminaChanged"))
	void RecieveStaminaChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MaxStaminaChanged"))
	void RecieveMaxStaminaChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "HungerChanged"))
	void RecieveHungerChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MaxHungerChanged"))
	void RecieveMaxHungerChanged(float NewHealth, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "SpeedChanged"))
	void RecieveSpeedChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MeleeStrengthChanged"))
	void RecieveMeleeStrengthChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MagicStrengthChanged"))
	void RecieveMagicStrengthChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "ToolStrengthChanged"))
	void RecieveToolStrengthChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "DefenseChanged"))
	void RecieveDefenseChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "ArmorChanged"))
	void RecieveArmorChanged(float NewValue, float OldValue);
};
