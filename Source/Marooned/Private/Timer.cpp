// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"
#include <Kismet/GameplayStatics.h>

Timer::Timer()
{
	UGameplayStatics::GetAccurateRealTime(PrevSeconds, PrevPartialSeconds);
}

Timer::~Timer()
{
}

double Timer::GetElapsedTimeSec()
{
	int32 Seconds{};
	double PartialSeconds{};

	UGameplayStatics::GetAccurateRealTime(Seconds, PartialSeconds);

	double ElapsedTime = (Seconds - PrevSeconds) + (PartialSeconds - PrevPartialSeconds);

	PrevSeconds = Seconds;
	PrevPartialSeconds = PartialSeconds;

	return ElapsedTime;
}
