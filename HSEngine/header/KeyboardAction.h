#pragma once

#include "SDL.h"
#include "InputAction.h"

//��� Keyboard Input���� �θ�
class KeyboardAction : public InputAction
{
	
public:
	void BeginInput() override {};
	void HoldInput() override {};
	void EndInput() override {};
protected:
	KeyboardAction(unsigned int code) : InputAction(code,CONTROLLER_KEYBOARD)
	{

	}
	virtual ~KeyboardAction() {};
};