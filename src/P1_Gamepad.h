#pragma once
#include <SDL.h>

struct Controller;

namespace Input
{
	namespace Gamepad
	{
		bool Initialize(Controller* gamepad);
		void Shutdown(Controller* gamepad);
	}
}

struct Controller
{
	SDL_GameController* controller = { 0 };
	uint8_t controllerID = 0;
};