#pragma once

#include "SDL.h"
#include "InputHandler.h"
#include "../MouseMoving.h"

//Mouse input들을 관리함
class MouseHandler :public InputHandler
{
public:
	DEFINE_COMPONENT(MouseHandler, InputHandler, true);
public:
	MouseHandler();
	void Start() override;
	void Update() override;

	void SetMouseMovingX(MouseMoving* x);
	void SetMouseMovingY(MouseMoving* y);

private:
	Uint32 current_mouse;
	MouseMoving* movingX;
	MouseMoving* movingY;
	int mouseX, mouseY;
};