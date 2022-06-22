#include "../header/RenderingMachineSDL.h"

RenderingMachineSDL::RenderingMachineSDL(SDL_Renderer* renderer) : renderer2d(renderer)
{

}

void RenderingMachineSDL::InitRenderer()
{
}

void RenderingMachineSDL::ReadyRenderer()
{
}

void RenderingMachineSDL::FinishRenderer()
{
	SDL_RenderPresent(renderer2d);
}