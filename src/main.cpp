#include "P1_Game.h"
#include "P1_Log.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

int main(int argc, char* args[])
{
	Game* game = new Game;
	if (!InitializeGame(game))
	{
		LOG_FATAL("Error starting Game. See logs!");
		return(-1);
	}

	const uint32_t PHYSICS_DT = 50;  // milliseconds
	uint32_t physics_accum = 0;
	uint32_t last_frame = SDL_GetTicks();

	while (IsRunning(game))
	{
		//@Performance: Is this the best place and method for obtaining and keeping
		//a delta time?
		//UpdateDelta(&game->DeltaClock);

		uint32_t now = SDL_GetTicks();
		uint32_t dt = now - last_frame;
		last_frame = now;

		physics_accum += dt;
		while (physics_accum >= PHYSICS_DT)
		{
			Update(game, PHYSICS_DT / 1000.0f);
			physics_accum -= PHYSICS_DT;
		}
		HandleInput(game);
		Draw(game, dt / 1000.0f);

		LOG_INFO("DT: {0}", dt);
	}

	ShutdownGame(game);

	delete game;
	game = nullptr;

	return(0);
}