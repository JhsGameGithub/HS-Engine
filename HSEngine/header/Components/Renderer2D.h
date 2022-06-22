#pragma once

#include "SDL.h"
#include "Renderer.h"

//2D ���������� ���� �߰� �θ� Ŭ����
class Renderer2D :public Renderer
{
public:
	DEFINE_COMPONENT(Renderer2D, Renderer, false);

public:
	Renderer2D(SDL_Renderer*& renderer2d) :renderer(renderer2d) {};

public:
	void Rendering() override {};
	virtual ~Renderer2D() {};

protected:
	SDL_Renderer* renderer;
};