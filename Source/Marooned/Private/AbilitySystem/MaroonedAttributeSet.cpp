// Fill out your copyright notice in the Description page of Project Settings.


#include "MaroonedAttributeSet.h"
#include <GameplayEffectExtension.h>
#include "Net/UnrealNetwork.h"


void UMaroonedAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UMaroonedAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		float NewHealth = GetHealth() - Data.EvaluatedData.Magnitude;
		NewHealth = FMath::Clamp(NewHealth, 0.0f, GetMaxHealth());

		SetHealth(NewHealth);
	}
}


void UMaroonedAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Health, OldHealth);
}

void UMaroonedAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, MaxHealth, OldMaxHealth);
}

void UMaroonedAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Mana, OldMana);
}

void UMaroonedAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, MaxMana, OldMaxMana);
}

void UMaroonedAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Stamina, OldStamina);
}

void UMaroonedAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, MaxStamina, OldMaxStamina);
}

void UMaroonedAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Hunger, OldHunger);
}

void UMaroonedAttributeSet::OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, MaxHunger, OldMaxHunger);
}

void UMaroonedAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Speed, OldSpeed);
}

void UMaroonedAttributeSet::OnRep_MeleeStrength(const FGameplayAttributeData& OldMeleeStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, MeleeStrength, OldMeleeStrength);
}

void UMaroonedAttributeSet::OnRep_MagicStrength(const FGameplayAttributeData& OldMagicStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, MagicStrength, OldMagicStrength);
}

void UMaroonedAttributeSet::OnRep_ToolStrength(const FGameplayAttributeData& OldToolStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, ToolStrength, OldToolStrength);
}

void UMaroonedAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Defense, OldDefense);
}

void UMaroonedAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMaroonedAttributeSet, Armor, OldArmor);
}

void UMaroonedAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, MaxHunger, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, MeleeStrength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, MagicStrength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, ToolStrength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMaroonedAttributeSet, Defense, COND_None, REPNOTIFY_Always);
}
