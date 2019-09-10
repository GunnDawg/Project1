#pragma once
#include <SDL.h>

struct Gamepad_t;

namespace Input
{
	namespace Gamepad
	{
		bool Initialize(Gamepad_t* gamepad);
		void Shutdown(Gamepad_t* gamepad);
	}
}

struct Gamepad_t
{
	SDL_GameController* controller = { 0 };
	uint8_t controllerID = 0;
};