#pragma once

#include "SDL.h"
#include "RenderingMachine.h"

//SDL ·»´õ¸µ¸Ó½Å
class RenderingMachineSDL : public RenderingMachine
{
public:
	RenderingMachineSDL(SDL_Renderer* renderer);

public:
	void InitRenderer() override;
	void ReadyRenderer() override;
	void FinishRenderer() override;

private:
	SDL_Renderer* renderer2d;
};