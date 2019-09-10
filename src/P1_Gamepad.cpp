#include "P1_Gamepad.h"
#include "P1_Log.h"

namespace Input
{
	namespace Gamepad
	{
		bool Initialize(Controller* gamepad)
		{
			if (SDL_NumJoysticks())
			{
				if (SDL_IsGameController(gamepad->controllerID))
				{
					gamepad->controller = SDL_GameControllerOpen(gamepad->controllerID);
					if (gamepad->controller)
					{
						LOG_INFO("Controller successfully initialized");
						return(1);
					}
					else
					{
						LOG_FATAL("Error setting up controller");
						return(0);
					}
				}
				else
				{
					LOG_FATAL("Device is not a recognized controller");
					return(0);
				}
			}
			else
			{
				LOG_FATAL("No Gamepads Detected");
				return(0);
			}
		}

		void Shutdown(Controller* gamepad)
		{
			if (gamepad->controller)
			{
				SDL_GameControllerClose(gamepad->controller);
				gamepad->controller = nullptr;
			}
		}
	}
}
