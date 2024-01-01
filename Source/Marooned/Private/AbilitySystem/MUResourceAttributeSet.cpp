// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MUResourceAttributeSet.h"
#include <GameplayEffectExtension.h>


void UMUResourceAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UMUResourceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetEffectContext();

	const FHitResult* HitResult = EffectContext.GetHitResult();

	if (HitResult)
	{
		if (!(HitResult->Component.IsValid()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("HitResult Component Not Valid"));
			return;
		}

		FString msg = FString::Printf(TEXT("Hit Actor: %s, Component: %s, Index: %i"),
			*(HitResult->GetActor()->GetName()),
			*(HitResult->Component->GetName()),
			HitResult->Item
		);

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, msg);

		OnDamageRecieved.ExecuteIfBound(Data);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("HitResult Not Found"));
	}


}