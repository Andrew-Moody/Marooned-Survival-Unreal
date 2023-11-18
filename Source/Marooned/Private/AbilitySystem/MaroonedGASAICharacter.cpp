// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MaroonedGASAICharacter.h"
#include "AbilitySystem/MaroonedAbilitySystemComponent.h"
#include "AbilitySystem/MaroonedAttributeSet.h"

// Sets default values
AMaroonedGASAICharacter::AMaroonedGASAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UMaroonedAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	// Not clear if this needs to be called in PossessedBy for AI as well but went ahead just to be safe
	//AbilitySystemComponent->InitAbilityActorInfo(this, this);

	AttributeSet = CreateDefaultSubobject<UMaroonedAttributeSet>(TEXT("AttributeSet"));

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
		.AddUObject(this, &AMaroonedGASAICharacter::HealthChanged);
}

// Called when the game starts or when spawned
void AMaroonedGASAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaroonedGASAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMaroonedGASAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMaroonedGASAICharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AMaroonedGASAICharacter::HealthChanged(const FOnAttributeChangeData& Data)
{
	RecieveHealthChanged(Data.NewValue, Data.OldValue);
}

