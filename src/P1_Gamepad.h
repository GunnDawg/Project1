#pragma once
#include <SDL.h>

struct GamePad;

bool InitializeGamepad(GamePad* gamepad);
void ShutdownGamepad(GamePad* gamepad);

struct GamePad
{
	SDL_GameController* controller;
};