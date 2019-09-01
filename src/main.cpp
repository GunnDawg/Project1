#include "P1_Game.h"
#include "P1_Log.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

Game* game = new Game;

const float PHYSICS_DT = 50;  // milliseconds
float dt = 0.0f;
float physics_accum = 0.0f;
float dt_prev = 0.0f;

int main(int argc, char* args[])
{
	if (!InitializeGame(game))
	{
		LOG_FATAL("Error starting Game. See logs!");
		return(-1);
	}

	dt_prev = SDL_GetTicks();

	while (IsRunning(game))
	{
		//@Performance: Is this the best place and method for obtaining and keeping
		//a delta time?
		//UpdateDelta(&game->DeltaClock);

		dt = SDL_GetTicks() - dt_prev;
		dt_prev = dt;
		physics_accum += dt;
		while (physics_accum >= PHYSICS_DT)
		{
			Update(game, PHYSICS_DT);
			physics_accum -= PHYSICS_DT;
		}
		HandleInput(game);
		Draw(game, dt);

		LOG_INFO("DT: {0}", dt);
	}

	ShutdownGame(game);

	delete game;
	game = nullptr;

	return(0);
}