#pragma once
#include <SDL.h>
#include <stdint.h>

struct GameWindow;

namespace Window
{
	bool Initialize(GameWindow* window);
	void Shutdown(GameWindow* window);
}

struct GameWindow
{
	const char* mTitle;
	uint16_t mWidth;
	uint16_t mHeight;

	SDL_Window* mWindow;
	SDL_GLContext mContext;
};