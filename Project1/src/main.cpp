#include "P1_Game.h"
#include "P1_Log.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

Game* game = new Game;

int main(int argc, char* args[])
{
	if (!InitializeGame(game))
	{
		LOG_FATAL("Error starting Game. See logs!");
		return(-1);
	}

	while (IsRunning(game))
	{
		//@Performance: Is this the best place and method for obtaining and keeping
		//a delta time?
		UpdateDelta(&game->DeltaClock);

		HandleInput(game);
		Update(game);
		Draw(game);
	}

	ShutdownGame(game);

	delete game;
	game = nullptr;

	return(0);
}