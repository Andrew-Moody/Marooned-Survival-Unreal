// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MUBaseAttributeSet.h"
#include <AbilitySystemComponent.h>
#include "MUResourceAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class UMUResourceAttributeSet : public UMUBaseAttributeSet
{
	GENERATED_BODY()
	
public:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;


	DECLARE_DELEGATE_OneParam(OnDamageRecievedSignature, const FGameplayEffectModCallbackData&);

	OnDamageRecievedSignature OnDamageRecieved;
};
