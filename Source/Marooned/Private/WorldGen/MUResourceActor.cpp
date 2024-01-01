// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGen/MUResourceActor.h"
#include "MUResourceInstanceComponent.h"


AMUResourceActor::AMUResourceActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMUResourceActor::StartHitFX(const FHitResult& HitResult)
{
	StartHitFX_BPImpl(HitResult);
}

void AMUResourceActor::StartDeathFX(const FHitResult& HitResult)
{
	StartDeathFX_BPImpl(HitResult);
}

void AMUResourceActor::FinishFX()
{
	OnFinishFX.ExecuteIfBound();

	Destroy();
}
