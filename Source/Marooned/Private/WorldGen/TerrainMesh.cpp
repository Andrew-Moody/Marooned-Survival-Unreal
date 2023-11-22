// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGen/TerrainMesh.h"
#include "ProceduralMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"


// Sets default values
ATerrainMesh::ATerrainMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));

	Mesh->SetCollisionProfileName(FName("BlockAllDynamic"), true);

	ResizeMesh(10, 10, 100);
}

// Called when the game starts or when spawned
void ATerrainMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATerrainMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATerrainMesh::UpdateMesh(int32 NewWidthX, int32 NewWidthY, float NewTileSize, float NewNoiseScale, float NewHeight)
{
	if (WidthX != NewWidthX || WidthY != NewWidthY || TileSize != NewTileSize)
	{
		ResizeMesh(NewWidthX, NewWidthY, NewTileSize);
	}

	FTimePair StartTime = GetAccurateTime();

	int32 Vert{};

	for (int32 i = 0; i <= WidthX; ++i)
	{
		for (int32 j = 0; j <= WidthY; ++j)
		{
			float Z =  NewHeight * FMath::PerlinNoise2D({ i * NewNoiseScale, j * NewNoiseScale });

			Vertices[Vert].Z = Z;
			++Vert;
		}
	}

	FTimePair HeightsTime = GetAccurateTime();

	// Pass empty vectors for now since these paramaters are optional
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;

	Mesh->UpdateMeshSection_LinearColor(0, Vertices, Normals, UVCoords, VertexColors, Tangents, false);

	FTimePair UpdateMeshTime = GetAccurateTime();

	FTimePair FinishTime = GetAccurateTime();

	float TotalSeconds = (FinishTime - StartTime).GetTime();
	float HeightsSeconds = (HeightsTime - StartTime).GetTime();
	float UpdateMeshSeconds = (UpdateMeshTime - HeightsTime).GetTime();

	UE_LOG(LogTemp, Warning, TEXT("Resized Mesh Total: %f, Height: %f, UpdateMesh: %f "),
		TotalSeconds, HeightsSeconds, UpdateMeshSeconds);
}


void ATerrainMesh::ResizeMesh(int32 NewWidthX, int32 NewWidthY, float NewTileSize)
{
	UE_LOG(LogTemp, Warning, TEXT("Resizing Mesh with size: %d"), NewWidthX);

	FTimePair StartTime = GetAccurateTime();

	WidthX = NewWidthX;
	WidthY = NewWidthY;
	TileSize = NewTileSize;

	int32 VertCount = (WidthX + 1) * (WidthY + 1);

	int32 OffsetX = WidthX + 1;
	int32 OffsetY = WidthY + 1;

	
	Vertices.Empty();
	Vertices.Reserve(VertCount);

	for (int32 i = 0; i <= WidthX; ++i)
	{
		for (int32 j = 0; j <= WidthY; ++j)
		{
			float x = i * TileSize;
			float y = j * TileSize;

			Vertices.Add(FVector(x, y, 0));
		}
	}

	FTimePair VertexTime = GetAccurateTime();


	Triangles.Empty();
	Triangles.Reserve(WidthX * WidthY * 6);

	for (int32 i = 0; i < WidthX; ++i)
	{
		for (int32 j = 0; j < WidthY; ++j)
		{
			Triangles.Add(OffsetY * i + j);
			Triangles.Add(OffsetY * i + j + 1);
			Triangles.Add(OffsetY * (i + 1) + j + 1);

			Triangles.Add(OffsetY * i + j);
			Triangles.Add(OffsetY * (i + 1) + j + 1);
			Triangles.Add(OffsetY * (i + 1) + j);
		}
	}

	FTimePair TriangleTime = GetAccurateTime();

	UVCoords.Empty();
	UVCoords.Reserve(VertCount);

	for (int32 i = 0; i <= WidthX; ++i)
	{
		for (int32 j = 0; j <= WidthY; ++j)
		{
			float x = i / (float)WidthX;
			float y = j / (float)WidthY;

			UVCoords.Add(FVector2D(x, y));
		}
	}

	FTimePair UVCoordTime = GetAccurateTime();


	// Pass empty vectors for now since these paramaters are optional
	TArray<FVector> Normals;
	TArray<FLinearColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;

	Mesh->CreateMeshSection_LinearColor(
		0,
		Vertices,
		Triangles,
		Normals,
		UVCoords,
		VertexColors,
		Tangents,
		bEnableCollision
	);


	ECollisionEnabled::Type enabled = Mesh->GetCollisionEnabled();

	UE_LOG(LogTemp, Warning, TEXT("CollisionEnabled Type: %d"), enabled);


	FTimePair CreateMeshTime = GetAccurateTime();

	Mesh->SetMaterial(0, Material);

	FTimePair FinishTime = GetAccurateTime();

	float TotalSeconds = (FinishTime - StartTime).GetTime();
	float VertexSeconds = (VertexTime - StartTime).GetTime();
	float TriangleSeconds = (TriangleTime - VertexTime).GetTime();
	float UVCoordSeconds = (UVCoordTime - TriangleTime).GetTime();
	float CreateMeshSeconds = (CreateMeshTime - UVCoordTime).GetTime();

	UE_LOG(LogTemp, Warning, TEXT("Resized Mesh Total: %f, Vertex: %f, Triangle: %f, UVCoord: %f, CreateMesh: %f "),
		TotalSeconds, VertexSeconds, TriangleSeconds, UVCoordSeconds, CreateMeshSeconds);
}

ATerrainMesh::FTimePair ATerrainMesh::GetAccurateTime()
{
	FTimePair CurrTime;

	UGameplayStatics::GetAccurateRealTime(CurrTime.Seconds, CurrTime.PartialSeconds);

	return CurrTime;
}
