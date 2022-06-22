#include "../header/Components/MouseHandler.h"

MouseHandler::MouseHandler() : InputHandler(CONTROLLER_MOUSE), movingX(nullptr), movingY(nullptr)
{

}
void MouseHandler::Start()
{
}

void MouseHandler::Update()
{
	SDL_PumpEvents();

	current_mouse = SDL_GetMouseState(&mouseX, &mouseY);

	movingX->MouseUpdate(mouseX);
	movingY->MouseUpdate(mouseY);

	for (auto input : input_map)
	{
		if (current_mouse & SDL_BUTTON(input.second->GetInput()) &&
			!*previous_input[input.second->GetInput()])
		{
			*previous_input[input.second->GetInput()] = current_mouse & SDL_BUTTON(input.second->GetInput());
			input.second->BeginInput();
		}
		if (current_mouse & SDL_BUTTON(input.second->GetInput()) &&
			*previous_input[input.second->GetInput()])
		{
			input.second->HoldInput();
		}
		if (!(current_mouse & SDL_BUTTON(input.second->GetInput())) &&
			*previous_input[input.second->GetInput()])
		{
			*previous_input[input.second->GetInput()] = current_mouse & SDL_BUTTON(input.second->GetInput());
			input.second->EndInput();
		}
	}
}

void MouseHandler::SetMouseMovingX(MouseMoving* x)
{
	movingX = x;
}
void MouseHandler::SetMouseMovingY(MouseMoving* y)
{
	movingY = y;
}
