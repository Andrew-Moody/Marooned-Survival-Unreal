// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorProxyHandle.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FActorProxyHandle
{
	GENERATED_BODY()

	FActorProxyHandle();

	FActorProxyHandle(AActor* Actor, UPrimitiveComponent* Component, int32 Index);

	FActorProxyHandle(const FActorProxyHandle& Other);

	bool operator==(const FActorProxyHandle& Other)
	{
		return Equals(Other);
	}

	bool Equals(const FActorProxyHandle& Other)
	{
		return Actor == Other.Actor && Component == Other.Component && Index == Other.Index;
	}

	UPROPERTY(BlueprintReadWrite)
	AActor* Actor;

	UPROPERTY(BlueprintReadWrite)
	UPrimitiveComponent* Component;

	UPROPERTY(BlueprintReadWrite)
	int32 Index;
};

uint32 GetTypeHash(const FActorProxyHandle& ActorProxyHandle);
