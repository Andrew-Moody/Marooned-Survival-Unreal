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


	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
		.AddUObject(this, &AMaroonedGASPlayerState::HealthChanged);



	// Default frequency for player state is low enough to introduce noticeable lag
	NetUpdateFrequency = 30.0f;
}

UAbilitySystemComponent* AMaroonedGASPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMaroonedGASPlayerState::HealthChanged(const FOnAttributeChangeData& Data)
{
	RecieveHealthChanged(Data.NewValue, Data.OldValue);
}
