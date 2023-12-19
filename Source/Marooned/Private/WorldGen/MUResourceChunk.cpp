// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGen/MUResourceChunk.h"

// Sets default values
AMUResourceChunk::AMUResourceChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Hism = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("Instances"));

}

// Called when the game starts or when spawned
void AMUResourceChunk::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMUResourceChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMUResourceChunk::SetMesh(UStaticMesh* Mesh)
{
	Hism->SetStaticMesh(Mesh);
}


void AMUResourceChunk::SetMaterial(UMaterialInterface* Material)
{

}

