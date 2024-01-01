// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class Timer
{
public:
	Timer();
	~Timer();

	double GetElapsedTimeSec();

private:

	int32 PrevSeconds{};
	double PrevPartialSeconds{};
};
