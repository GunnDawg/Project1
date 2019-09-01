#pragma once
#include <SDL.h>

struct Mouse;

void UpdateCursorPosition(Mouse* mouse, SDL_Event* evnt);

struct Mouse
{
	int y;
	int x;
};