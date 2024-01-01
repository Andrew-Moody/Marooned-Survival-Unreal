// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <AttributeSet.h>
#include <AbilitySystemComponent.h>
#include "MUBaseAttributeSet.h"
#include "MaroonedAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class MAROONED_API UMaroonedAttributeSet : public UMUBaseAttributeSet
{
	GENERATED_BODY()
	
public:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;


	// Health
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Health);

	UPROPERTY(BlueprintReadonly, Category = "Attribute|Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, MaxHealth);

	// Mana
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Mana);

	UPROPERTY(BlueprintReadonly, Category = "Attribute|Mana", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, MaxMana);

	// Stamina
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Stamina", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Stamina);

	UPROPERTY(BlueprintReadonly, Category = "Attribute|Stamina", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, MaxStamina);

	// Hunger
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Hunger", ReplicatedUsing = OnRep_Hunger)
	FGameplayAttributeData Hunger;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Hunger);

	UPROPERTY(BlueprintReadonly, Category = "Attribute|Hunger", ReplicatedUsing = OnRep_MaxHunger)
	FGameplayAttributeData MaxHunger;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, MaxHunger);

	// Speed
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Speed", ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Speed);

	// Melee Strength
	UPROPERTY(BlueprintReadonly, Category = "Attribute|MeleeStrength", ReplicatedUsing = OnRep_MeleeStrength)
	FGameplayAttributeData MeleeStrength;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, MeleeStrength);

	// Magic Strength
	UPROPERTY(BlueprintReadonly, Category = "Atribute|MagicStrength", ReplicatedUsing = OnRep_MagicStrength)
	FGameplayAttributeData MagicStrength;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, MagicStrength);

	// Tool Strength
	UPROPERTY(BlueprintReadonly, Category = "Attribute|ToolStrength", ReplicatedUsing = OnRep_ToolStrength)
	FGameplayAttributeData ToolStrength;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, ToolStrength);

	// Defense
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Defense", ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Defense);

	// Armor
	UPROPERTY(BlueprintReadonly, Category = "Attribute|Armor", ReplicatedUsing = OnRep_Armor)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Armor);


	// Meta Attribute to hold a server side temp value and is not replicated
	/*UPROPERTY(BlueprintReadonly, Category = "Attribute|Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UMaroonedAttributeSet, Damage);*/

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);
	UFUNCTION()
	virtual void OnRep_Hunger(const FGameplayAttributeData& OldHunger);
	UFUNCTION()
	virtual void OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger);

	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	UFUNCTION()
	virtual void OnRep_MeleeStrength(const FGameplayAttributeData& OldMeleeStrength);
	UFUNCTION()
	virtual void OnRep_MagicStrength(const FGameplayAttributeData& OldMagicStrength);
	UFUNCTION()
	virtual void OnRep_ToolStrength(const FGameplayAttributeData& OldToolStrength);
	UFUNCTION()
	virtual void OnRep_Defense(const FGameplayAttributeData& OldDefense);
	UFUNCTION()
	virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
