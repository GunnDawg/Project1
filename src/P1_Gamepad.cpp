#include "P1_Gamepad.h"
#include "P1_Log.h"

bool InitializeGamepad(GamePad* gamepad)
{
	if (SDL_NumJoysticks())
	{
		if (SDL_IsGameController(0))
		{
			gamepad->controller = SDL_GameControllerOpen(0);
		}
		else
		{
			LOG_FATAL("Device is not a recognized controller");
			return(0);
		}
	}
	else
	{
		LOG_INFO("No Gamepads Detected");
		return(0);
	}

	return(1);
}

void ShutdownGamepad(GamePad* gamepad)
{
	if (gamepad->controller)
	{
		SDL_GameControllerClose(gamepad->controller);
		gamepad->controller = nullptr;
	}
}