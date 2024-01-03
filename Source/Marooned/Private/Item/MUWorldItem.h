// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemTypes.h"
#include "MUWorldItem.generated.h"

UCLASS()
class AMUWorldItem : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMUWorldItem();

	UFUNCTION(BlueprintCallable)
	void SetItemStack(const FMUItemStack& NewItemStack);

	UFUNCTION(BlueprintCallable)
	const FMUItemStack& GetItemStack() const { return ItemStack; }

	// Fun fact this function is declared automatically if the class has any replicated properties
	//virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	// Apply any visual changes in response to item change
	// Will currently only be called if either ItemId or Count is different
	UFUNCTION()
	virtual void OnRep_ItemStack(const FMUItemStack& OldValue);

	UFUNCTION(BlueprintImplementableEvent)
	void PrintDebugString(const FString& String);

	void SetupItemMesh(const FMUItemStack& OldValue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ItemStack)
	FMUItemStack ItemStack{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent{};
};
