// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MaroonedGASPlayerState.h"

#include "MaroonedAbilitySystemComponent.h"
#include "MaroonedAttributeSet.h"

AMaroonedGASPlayerState::AMaroonedGASPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UMaroonedAbilitySystemComponent>(TEXT("MaroonedAblitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Should be mixed for multiplayer player characters and minimal for multiplayer AI characters
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Can't InitAbilityActorInfo here because character may not be possessed yet

	AttributeSet = CreateDefaultSubobject<UMaroonedAttributeSet>(TEXT("MaroonedAttributeSet"));


	// Default frequency for player state is low enough to introduce noticeable lag
	NetUpdateFrequency = 30.0f;


	// Subscribe to attribute change delegates
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::MaxManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStaminaAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::StaminaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxStaminaAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::MaxStaminaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHungerAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::HungerChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHungerAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::MaxHungerChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetSpeedAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::SpeedChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMeleeStrengthAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::MeleeStrengthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMagicStrengthAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::MagicStrengthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetToolStrengthAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::ToolStrengthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetDefenseAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::DefenseChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetArmorAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::ArmorChanged);
}

UAbilitySystemComponent* AMaroonedGASPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMaroonedGASPlayerState::HealthChanged(const FOnAttributeChangeData& Data)
{
	RecieveHealthChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	RecieveMaxHealthChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::ManaChanged(const FOnAttributeChangeData& Data)
{
	RecieveManaChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	RecieveMaxManaChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::StaminaChanged(const FOnAttributeChangeData& Data)
{
	RecieveStaminaChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::MaxStaminaChanged(const FOnAttributeChangeData& Data)
{
	RecieveMaxStaminaChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::HungerChanged(const FOnAttributeChangeData& Data)
{
	RecieveHungerChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::MaxHungerChanged(const FOnAttributeChangeData& Data)
{
	RecieveMaxHungerChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::SpeedChanged(const FOnAttributeChangeData& Data)
{
	RecieveSpeedChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::MeleeStrengthChanged(const FOnAttributeChangeData& Data)
{
	RecieveMeleeStrengthChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::MagicStrengthChanged(const FOnAttributeChangeData& Data)
{
	RecieveMagicStrengthChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::ToolStrengthChanged(const FOnAttributeChangeData& Data)
{
	RecieveToolStrengthChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::DefenseChanged(const FOnAttributeChangeData& Data)
{
	RecieveDefenseChanged(Data.NewValue, Data.OldValue);
}

void AMaroonedGASPlayerState::ArmorChanged(const FOnAttributeChangeData& Data)
{
	RecieveArmorChanged(Data.NewValue, Data.OldValue);
}
