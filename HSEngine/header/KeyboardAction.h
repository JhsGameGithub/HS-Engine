#pragma once

#include "SDL.h"
#include "InputAction.h"

//모든 Keyboard Input들의 부모
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