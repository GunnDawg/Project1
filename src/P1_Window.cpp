#include "P1_Window.h"
#include "P1_Log.h"

#include <gl/glew.h>

bool InitializeWindow(GameWindow* window)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	window->Window = SDL_CreateWindow(window->Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window->Width, window->Height, SDL_WINDOW_OPENGL);
	if (!window->Window)
	{
		LOG_FATAL("Error creating SDL_Window!");
		ShutdownWindow(window);
		return(0);
	}

	window->Context = SDL_GL_CreateContext(window->Window);
	if (!window->Context)
	{
		LOG_FATAL("Error creating OpenGL Context!");
		ShutdownWindow(window);
		return(0);
	}

	if (glewInit() != GLEW_OK)
	{
		LOG_FATAL("Error initializing GLEW!");
		ShutdownWindow(window);
		return(0);
	}

#ifdef _DEBUG
	LOG_INFO("{0}", glGetString(GL_VERSION));
#endif

	if (SDL_GL_SetSwapInterval(1) != 0)
	{
		LOG_ERROR("Error setting SwapInterval / VSync!");
		return(0);
	}

	return(1);
}

void ShutdownWindow(GameWindow* window)
{
	if (window->Window)
	{
		SDL_DestroyWindow(window->Window);
		window->Window = nullptr;
	}
}