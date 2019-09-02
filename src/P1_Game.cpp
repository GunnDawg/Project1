#include "P1_Game.h"
#include <GL/glew.h>

bool IsRunning(const Game* game)
{
	return game->IsRunning;
}

bool InitializeGame(Game* game)
{
	Logger::Init();

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LOG_FATAL("Error initializing SDL!");
		return(0);
	}

	if(!InitializeWindow(&game->Window))
	{
		LOG_FATAL("Error initializing SDL_Window!");
		return(0);
	}

    SDL_GetRelativeMouseState(&game->mouse.x, &game->mouse.y);

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
			}

            case SDL_MOUSEMOTION:
            {
                //game->mouse_x = evnt.motion.x;
                //game->mouse_y = evnt.motion.y;
				UpdateCursorPosition(&game->mouse, &evnt);
                break;
            }

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
	glClearColor((float)game->mouse.x / game->Window.Width,
                 (float)game->mouse.y / game->Window.Height, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	SDL_GL_SwapWindow(game->Window.Window);
}

void ShutdownGame(Game* game)
{
	ShutdownWindow(&game->Window);

	SDL_Quit();
}