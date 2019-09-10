#pragma once
#include <SDL.h>

struct Mouse_t;

namespace Input
{
	namespace Mouse
	{
		void Update(Mouse_t* mouse, SDL_Event* evnt);
	}
}

struct Mouse_t
{
	int y;
	int x;
};