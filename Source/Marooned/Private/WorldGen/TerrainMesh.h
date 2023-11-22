// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainMesh.generated.h"

class UProceduralMeshComponent;


UCLASS()
class ATerrainMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerrainMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:

	UFUNCTION(BlueprintCallable)
	virtual void UpdateMesh(int32 NewWidthX, int32 NewWidthY, float NewTileSize, float NewNoiseScale, float NewHeight);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* Mesh{ nullptr };

	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* Material;

	UPROPERTY(EditDefaultsOnly)
	bool bEnableCollision;

	UPROPERTY(EditDefaultsOnly)
	bool bUsePMCLibrary;

protected:

	virtual void ResizeMesh(int32 NewWidthX, int32 NewWidthY, float NewTileSize);

	int32 Seed;
	int32 WidthX;
	int32 WidthY;
	float TileSize;
	float Height;
	
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector2D> UVCoords;

	bool bSRGBConversion{ false };


public:

	struct FTimePair
	{
		int32 Seconds;
		float PartialSeconds;

		float GetTime()
		{
			return Seconds + PartialSeconds;
		}

		FTimePair& operator-=(const FTimePair& rhs)
		{
			Seconds -= rhs.Seconds;
			PartialSeconds -= rhs.PartialSeconds;

			return *this;
		}
	};

	FTimePair GetAccurateTime();
};

inline ATerrainMesh::FTimePair operator-(const ATerrainMesh::FTimePair& lhs, const ATerrainMesh::FTimePair& rhs)
{
	ATerrainMesh::FTimePair result = lhs;

	result -= rhs;

	return result;
}