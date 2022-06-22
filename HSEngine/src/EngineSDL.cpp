#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "../header/EngineSDL.h"
#include "../header/RenderingMachineOpenGL.h"
#include "../header/RenderingMachineSDL.h"

EngineSDL::EngineSDL(int game_width, int game_height) :width(game_height), height(game_height)
{

}

EngineSDL::~EngineSDL()
{
	delete machineOpenGL;
	delete machineSDL;
}

bool EngineSDL::InitGame()
{
	int oglIdx = -1;
	int nRD = SDL_GetNumRenderDrivers();
	for (int i = 0; i < nRD; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
		{
			if (!strcmp(info.name, "opengl"))
			{
				oglIdx = i;
			}
		}
	}

	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		pWindow = SDL_CreateWindow(
			"myEngine",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_OPENGL| SDL_WINDOW_RESIZABLE
		);

		if (pWindow != nullptr)
		{
			glcontext = SDL_GL_CreateContext(pWindow);

			if (glcontext != nullptr)
			{
				pRenderer = SDL_CreateRenderer(
					pWindow,
					oglIdx,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

				if (pRenderer == nullptr)
				{
					SDL_DestroyWindow(pWindow);
					SDL_Quit();
					return false;
				}
			}
			else
			{
				SDL_DestroyWindow(pWindow);
				SDL_Quit();
				return false;
			}
		}
		else
		{
			SDL_Quit();
			return false;
		}
	}
	else
	{
		return false;
	}

	machineOpenGL = new RenderingMachineOpenGL(pWindow);
	machineSDL = new RenderingMachineSDL(pRenderer);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}


void EngineSDL::Run()
{
	InitRenderer();


	SDL_Event events;
	int running = 1;

	CurrentScene->LoadScene();

	Time.initTimer();

	while (running)
	{
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT)
			{
				running = 0;
			}
		}
		Time.updateTimer();

		///GAMEPLAYING LOGIC///
		CurrentScene->PlayScene(Time.getElapsed());

		///RENDERING LOGIC///

		//RenderReady
		machineSDL->ReadyRenderer();
		machineOpenGL->ReadyRenderer();

		//Rendering
		CurrentScene->RenderScene(Time.getElapsed());

		//RenderFinish
		machineOpenGL->FinishRenderer();
		machineSDL->FinishRenderer();
	}
}

void EngineSDL::Terminate()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_GL_DeleteContext(glcontext);
	SDL_Quit();
}


void EngineSDL::InitRenderer()
{
	//SDL::Init
	machineSDL->InitRenderer();

	//OpenGL::Init
	machineOpenGL->InitRenderer();
}

SDL_Renderer* EngineSDL::GetSdlRenderer()
{
	return pRenderer;
}