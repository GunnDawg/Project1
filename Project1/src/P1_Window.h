#pragma once
#include <SDL.h>
#include <stdint.h>

struct GameWindow;

bool InitializeWindow(GameWindow* window);
void ShutdownWindow(GameWindow* window);

struct GameWindow
{
	const char* Title;
	uint16_t Width;
	uint16_t Height;

	SDL_Window* Window;
	SDL_GLContext Context;
};