#pragma once
#include <SDL.h>

struct GamePad;

namespace Gamepad
{
	bool Initialize(GamePad* gamepad);
	void Shutdown(GamePad* gamepad);
}

struct GamePad
{
	SDL_GameController* controller = { 0 };
	uint8_t controllerID = 0;
};