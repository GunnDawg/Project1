#include "P1_DeltaClock.h"
#include "P1_Log.h"
#include <SDL.h>

const double GETFREQUENCY = (1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

void UpdateDelta(DeltaClock* clock)
{
	uint64_t now = SDL_GetPerformanceCounter();
	double dt = static_cast<double>((now - clock->last_frame) * GETFREQUENCY);
	clock->last_frame = now;

	clock->physics_accum += dt;
}