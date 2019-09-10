#include "P1_Window.h"
#include "P1_Log.h"

#include <gl/glew.h>

namespace Window
{
	bool Initialize(Window_t* window)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window->mWindow = SDL_CreateWindow(window->mTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window->mWidth, window->mHeight, SDL_WINDOW_OPENGL);
		if (!window->mWindow)
		{
			LOG_FATAL("Error creating SDL_Window!");
			Window::Shutdown(window);
			return(0);
		}

		window->mContext = SDL_GL_CreateContext(window->mWindow);
		if (!window->mContext)
		{
			LOG_FATAL("Error creating OpenGL Context!");
			Window::Shutdown(window);
			return(0);
		}

		if (glewInit() != GLEW_OK)
		{
			LOG_FATAL("Error initializing GLEW!");
			Window::Shutdown(window);
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

	void Shutdown(Window_t* window)
	{
		if (window->mWindow)
		{
			SDL_DestroyWindow(window->mWindow);
			window->mWindow = nullptr;
		}
	}
}