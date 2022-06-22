#pragma once

#include "SDL.h"
#include "Game.h"
#include "Timer.h"
#include "RenderingMachine.h"


//SDL 엔진을 쓰는 게임
class EngineSDL : public Game
{
public:
	bool InitGame() override;

	void InitRenderer() override;

	void Run() override;

	void Terminate() override;

	SDL_Renderer* GetSdlRenderer();

	EngineSDL(int game_width, int game_hegiht);
	~EngineSDL();

private:
	//Initialize Instance
	Timer& Time = Timer::instance();

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_GLContext glcontext;

	int width;
	int height;

	RenderingMachine* machineOpenGL;
	RenderingMachine* machineSDL;

	//Rendering Machine Instance
};
