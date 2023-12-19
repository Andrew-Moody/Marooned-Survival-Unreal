// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/HierarchicalInstancedStaticMeshComponent.h>
#include "MUResourceChunk.generated.h"

UCLASS()
class AMUResourceChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMUResourceChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetMesh(UStaticMesh* Mesh);

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterialInterface* Material);

protected:

	UPROPERTY(BlueprintReadWrite)
	UHierarchicalInstancedStaticMeshComponent* Hism{ nullptr };
};
