#pragma once

#include <map>
#include <string>
#include <cassert>

#include "../InputAction.h"
#include "MonoBehaviour.h"
#include "../ControllerEnum.h"

class InputHandler : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(InputHandler, MonoBehaviour, true);
public:
	void AddInput(InputAction* input);

protected:
	InputHandler(CONTROLLER control);
	virtual ~InputHandler();

protected:
	std::map<unsigned int, InputAction*> input_map;
	std::map<unsigned int, bool*> previous_input;

private:
	CONTROLLER input_controller;
};
