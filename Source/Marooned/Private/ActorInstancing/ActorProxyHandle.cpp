// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorInstancing/ActorProxyHandle.h"

FActorProxyHandle::FActorProxyHandle()
	: Actor{ nullptr }, Component{ nullptr }, Index{ -1 }
{}

FActorProxyHandle::FActorProxyHandle(AActor* Actor, UPrimitiveComponent* Component, int32 Index)
	: Actor{ Actor }, Component{ Component }, Index{ Index }
{}

FActorProxyHandle::FActorProxyHandle(const FActorProxyHandle& Other)
	: Actor{ Other.Actor }, Component{ Other.Component }, Index{ Other.Index }
{}

uint32 GetTypeHash(const FActorProxyHandle &ActorProxyHandle)
{
	return FCrc::MemCrc32(&ActorProxyHandle, sizeof(FActorProxyHandle));
}
