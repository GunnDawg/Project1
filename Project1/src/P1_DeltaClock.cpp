#include "P1_DeltaClock.h"
#include <SDL.h>

#include <stdio.h>

void UpdateDelta(DeltaClock* clock)
{
	//@Note: Delta Time Calculations
	clock->LastTime = clock->CurrentTime;
	clock->CurrentTime = SDL_GetPerformanceCounter();
	clock->DeltaTime = static_cast<double>((clock->CurrentTime - clock->LastTime) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

	//@Note: Average Delta Time Calculations
	//@FixMe: This is sort of hackey but if we do this calculation at the beginning
	//of the game before the delta time has setttled, then it won't work correctly,
	//not really sure why?
	if (clock->DeltaTime < 100)
	{
		clock->TotalDeltaTime += clock->DeltaTime;
	}

	clock->TotalUpdates += 1;
	clock->AveragegDeltaTime = clock->TotalDeltaTime / clock->TotalUpdates;

#ifdef _DEBUG
	printf("Delta Time: %f\nAverage Delta Time: %f\n", clock->DeltaTime, clock->AveragegDeltaTime);
#endif
}