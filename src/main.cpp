#include "P1_Game.h"
#include "P1_Log.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

const double GETFREQUENCY = (1000 / static_cast<double>(SDL_GetPerformanceFrequency()));

int main(int argc, char* args[])
{
	Game* game = new Game;
	if (!System::Initialize(game))
	{
		LOG_FATAL("Error starting Game. See logs!");
		return(-1);
	}

	const uint32_t PHYSICS_DT = 50;  // milliseconds
	double physics_accum = 0.0;
	uint64_t last_frame = SDL_GetPerformanceCounter();

	while (System::IsRunning(game))
	{
		uint64_t now = SDL_GetPerformanceCounter();
		double dt = static_cast<double>((now - last_frame) * GETFREQUENCY);
		last_frame = now;

		physics_accum += dt;
		while (physics_accum >= PHYSICS_DT)
		{
			System::Update(game, PHYSICS_DT / 1000.0f);
			physics_accum -= PHYSICS_DT;
		}
		System::HandleInput(game);
		System::Draw(game, dt);

		//LOG_INFO("DT: {0}", dt);
	}

	System::Shutdown(game);

	delete game;
	game = nullptr;

	return(0);
}