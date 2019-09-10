#pragma once
#include <SDL.h>
#include <stdint.h>

struct Window_t;

namespace Window
{
	bool Initialize(Window_t* window);
	void Shutdown(Window_t* window);
}

struct Window_t
{
	const char* mTitle;
	uint16_t mWidth;
	uint16_t mHeight;

	SDL_Window* mWindow;
	SDL_GLContext mContext;
};