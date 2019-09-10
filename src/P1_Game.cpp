#include "P1_Game.h"
#include <GL/glew.h>

constexpr bool GamePadEnabled = true;

namespace System
{
	bool IsRunning(const Game_t* game)
	{
		return game->IsRunning;
	}

	bool Initialize(Game_t* game)
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

	void HandleInput(Game_t* game)
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
					Input::Mouse::Update(&game->mouse, &evnt);
				} break;

				default:
					break;
			}
		}
	}

	void Update(const Game_t* game, const float pDT)
	{

	}

	void Draw(const Game_t* game, double deltaTime)
	{
		glClearColor((float)game->mouse.x / game->Window.mWidth,
			(float)game->mouse.y / game->Window.mHeight, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		SDL_GL_SwapWindow(game->Window.mWindow);
	}

	void Shutdown(Game_t* game)
	{
		Window::Shutdown(&game->Window);
		Input::Gamepad::Shutdown(&game->Controller);
		SDL_Quit();
	}
}