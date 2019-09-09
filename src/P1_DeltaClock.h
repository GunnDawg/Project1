#pragma once
#include <SDL.h>

struct DeltaClock;

void UpdateDelta(DeltaClock* clock);

struct DeltaClock
{
	const uint32_t PHYSICS_DT = 50;  // milliseconds
	double physics_accum = 0.0;
	uint64_t last_frame = SDL_GetPerformanceCounter();
};