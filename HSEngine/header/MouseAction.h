#pragma once

#include "InputAction.h"
#include "SDL.h"

//��� Mouse Input���� �θ�
class MouseAction : public InputAction
{
public:
	void BeginInput() override {};
	void HoldInput() override {};
	void EndInput() override {};

protected:
	MouseAction(unsigned int mouseinput) : InputAction(mouseinput, CONTROLLER_MOUSE)
	{

	}
	virtual ~MouseAction() {};
};