#include "../header/Components/InputHandler.h"



InputHandler::InputHandler(CONTROLLER control) : input_controller(control)
{

}
InputHandler::~InputHandler()
{
	for (auto input : input_map)
	{
		delete input.second;
	}
	input_map.clear();

	for (auto input : previous_input)
	{
		delete input.second;
	}
	previous_input.clear();
}

void InputHandler::AddInput(InputAction* input)
{
	assert(input->GetController() == input_controller);

	unsigned int inputCode = input->GetInput();

	previous_input.insert({ inputCode,new bool(false) });
	input_map.insert({ inputCode,input });
	input->SetGameObject(gameObject);
}