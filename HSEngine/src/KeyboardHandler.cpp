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
		//���� ����
		if (current_keyboard[key.second->GetInput()] && !*previous_input[key.second->GetInput()])
		{
			*previous_input[key.second->GetInput()] = current_keyboard[key.second->GetInput()];
			key.second->BeginInput();
		}
		//������ ��
		if (current_keyboard[key.second->GetInput()] && *previous_input[key.second->GetInput()])
		{
			key.second->HoldInput();
		}
		//�� ����
		if (!current_keyboard[key.second->GetInput()] && *previous_input[key.second->GetInput()])
		{
			*previous_input[key.second->GetInput()] = current_keyboard[key.second->GetInput()];
			key.second->EndInput();
		}
	}
}