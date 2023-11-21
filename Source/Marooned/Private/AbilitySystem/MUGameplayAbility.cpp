// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MUGameplayAbility.h"
#include <AbilitySystemComponent.h>

void UMUGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);

	if (bActivateOnGranted)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, bAllowRemoteActivation);
	}
}
