// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MaroonedGASAICharacter.generated.h"

class UMaroonedAbilitySystemComponent;
class UMaroonedAttributeSet;
struct FOnAttributeChangeData;

UCLASS()
class AMaroonedGASAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMaroonedGASAICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;

protected:

	virtual void HealthChanged(const FOnAttributeChangeData& Data);

	virtual void TagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "HealthChanged"))
	void RecieveHealthChanged(float NewHealth, float OldHealth);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "TagChanged"))
	void RecieveTagChanged(const FGameplayTag ChangedTag, int32 NewCount);

	UPROPERTY()
	UMaroonedAbilitySystemComponent* AbilitySystemComponent{ nullptr };

	UPROPERTY(Transient)
	UMaroonedAttributeSet* AttributeSet{ nullptr };
};
