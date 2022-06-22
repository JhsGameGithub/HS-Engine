#include"../header/Components/KeyboardHandler.h"

KeyboardHandler::KeyboardHandler() : InputHandler(CONTROLLER_KEYBOARD)
{

}
void KeyboardHandler::Start()
{
}

void KeyboardHandler::Update()
{
	SDL_PumpEvents();
	current_keyboard = SDL_GetKeyboardState(NULL);
	
	for (auto key : input_map)
	{
		//누른 직후
		if (current_keyboard[key.second->GetInput()] && !*previous_input[key.second->GetInput()])
		{
			*previous_input[key.second->GetInput()] = current_keyboard[key.second->GetInput()];
			key.second->BeginInput();
		}
		//누르는 중
		if (current_keyboard[key.second->GetInput()] && *previous_input[key.second->GetInput()])
		{
			key.second->HoldInput();
		}
		//뗀 직후
		if (!current_keyboard[key.second->GetInput()] && *previous_input[key.second->GetInput()])
		{
			*previous_input[key.second->GetInput()] = current_keyboard[key.second->GetInput()];
			key.second->EndInput();
		}
	}
}