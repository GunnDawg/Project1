#include "P1_Game.h"
#include <GL/glew.h>

constexpr bool GamePadEnabled = true;

namespace System
{
	bool IsRunning(const Game* game)
	{
		return game->IsRunning;
	}

	bool Initialize(Game* game)
	{
		Logger::Init();

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0)
		{
			LOG_FATAL("Error initializing SDL!");
			return(0);
		}

		if (!Window::Initialize(&game->Window))
		{
			LOG_FATAL("Error initializing SDL_Window!");
			return(0);
		}

		if (game->UsingGamepad)
		{
			if (!Input::Gamepad::Initialize(&game->Controller))
			{
				LOG_FATAL("Error initializing Gamepad!");
				return(0);
			}
		}

		//SDL_GetMouseState(&game->mouse.x, &game->mouse.y);

		game->IsRunning = true;

		return(1);
	}

	void HandleInput(Game* game)
	{
		SDL_Event evnt;
		while (SDL_PollEvent(&evnt))
		{
			switch (evnt.type)
			{
				case SDL_QUIT:
				{
					game->IsRunning = false;
				} break;

				case SDL_KEYDOWN:
				{
					switch (evnt.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						{
							game->IsRunning = false;
						} break;

						default:
							break;
					}
				} break;

				case SDL_CONTROLLERBUTTONDOWN:
				{
					switch (evnt.cbutton.button)
					{
						case SDL_CONTROLLER_BUTTON_BACK:
						{
							game->IsRunning = false;
						} break;

						default:
							break;
					}
				} break;

				case SDL_MOUSEMOTION:
				{
					Input::Mouse::Update(&game->Mouse, &evnt);
				} break;

				default:
					break;
			}
		}
	}

	void Update(const Game* game, const float pDT)
	{

	}

	void Draw(const Game* game, double deltaTime)
	{
		glClearColor((float)game->Mouse.x / game->Window.mWidth,
			(float)game->Mouse.y / game->Window.mHeight, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		SDL_GL_SwapWindow(game->Window.mWindow);
	}

	void Shutdown(Game* game)
	{
		Window::Shutdown(&game->Window);
		Input::Gamepad::Shutdown(&game->Controller);
		SDL_Quit();
	}
}