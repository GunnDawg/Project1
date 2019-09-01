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

			default:
				break;
		}
	}
}

void Update(const Game* game)
{

}

void Draw(const Game* game)
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	SDL_GL_SwapWindow(game->Window.Window);
}

void ShutdownGame(Game* game)
{
	ShutdownWindow(&game->Window);

	SDL_Quit();
}