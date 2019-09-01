#pragma once
#include <stdint.h>

struct DeltaClock;

void UpdateDelta(DeltaClock* clock);

struct DeltaClock
{
	uint64_t CurrentTime = 0ULL;
	uint64_t LastTime = 0ULL;
	uint64_t TotalUpdates = 0ULL;
	double DeltaTime = NULL;
	double TotalDeltaTime = 0.0;
	double AveragegDeltaTime = 0.0;
};