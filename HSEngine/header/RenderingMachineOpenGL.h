#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "SDL.h"
#include "RenderingMachine.h"

//OpenGL ·»´õ¸µ ¸Ó½Å
class RenderingMachineOpenGL : public RenderingMachine 
{
public:
	RenderingMachineOpenGL(SDL_Window* window) : pWindow(window) {};

public:
	void InitRenderer() override;
	void ReadyRenderer() override;
	void FinishRenderer() override;

private:
	SDL_Window* pWindow;
};