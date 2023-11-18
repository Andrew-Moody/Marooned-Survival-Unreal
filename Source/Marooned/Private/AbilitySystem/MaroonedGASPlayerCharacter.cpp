// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MaroonedGASPlayerCharacter.h"
#include "AbilitySystem/MaroonedGASPlayerState.h"
#include "AbilitySystem/MaroonedAbilitySystemComponent.h"

// Sets default values
AMaroonedGASPlayerCharacter::AMaroonedGASPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaroonedGASPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaroonedGASPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMaroonedGASPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMaroonedGASPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AMaroonedGASPlayerState* playerState = GetPlayerState<AMaroonedGASPlayerState>();

	if (playerState)
	{
		AbilitySystemComponent = Cast<UMaroonedAbilitySystemComponent>(playerState->GetAbilitySystemComponent());

		AbilitySystemComponent->InitAbilityActorInfo(playerState, this);
	}
}

void AMaroonedGASPlayerCharacter::OnRep_PlayerState()
{
	AMaroonedGASPlayerState* playerState = GetPlayerState<AMaroonedGASPlayerState>();

	if (playerState)
	{
		AbilitySystemComponent = Cast<UMaroonedAbilitySystemComponent>(playerState->GetAbilitySystemComponent());

		AbilitySystemComponent->InitAbilityActorInfo(playerState, this);
	}
}

UAbilitySystemComponent* AMaroonedGASPlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

