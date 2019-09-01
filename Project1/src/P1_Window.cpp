#include "P1_Window.h"
#include <stdio.h>
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
		printf("Error creating SDL_Window!\n");
		ShutdownWindow(window);
		return(0);
	}

	window->Context = SDL_GL_CreateContext(window->Window);
	if (!window->Context)
	{
		printf("Error creating OpenGL Context!\n");
		ShutdownWindow(window);
		return(0);
	}

	if (glewInit() != GLEW_OK)
	{
		printf("Error initializing GLEW!\n");
		ShutdownWindow(window);
		return(0);
	}

#ifdef _DEBUG
	printf("%s\n", glGetString(GL_VERSION));
#endif

	SDL_GL_SetSwapInterval(1);

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