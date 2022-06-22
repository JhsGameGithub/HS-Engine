#pragma once

#include "SDL.h"
#include "Renderer.h"

//2D 렌더러들을 위한 중간 부모 클래스
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