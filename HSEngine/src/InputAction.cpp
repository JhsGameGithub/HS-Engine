#include "../header/InputAction.h"


InputAction::InputAction(unsigned int code, CONTROLLER control) : myInput(code), m_controller(control), gameObject(nullptr)
{

}

CONTROLLER InputAction::GetController()
{ 
	return m_controller;
}

unsigned int InputAction::GetInput() 
{ 
	return myInput;
}


void InputAction::SetGameObject(GameObject* obj)
{
	gameObject = obj;
}