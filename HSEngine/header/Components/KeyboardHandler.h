#pragma once

#include <string>
#include <vector>
#include <map>

#include "InputHandler.h"
#include "SDL.h"

//KeyboardAction 들을 관리
class KeyboardHandler : public InputHandler
{
public:
	DEFINE_COMPONENT(KeyboardHandler, InputHandler, true);
public:
	KeyboardHandler();
	void Start() override;
	
	void Update() override;

private:
	const Uint8* current_keyboard;
};