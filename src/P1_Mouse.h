#pragma once
#include <SDL.h>

struct Cursor;

namespace Input
{
	namespace Mouse
	{
		void Update(Cursor* mouse, SDL_Event* evnt);
	}
}

struct Cursor
{
	int y;
	int x;
};