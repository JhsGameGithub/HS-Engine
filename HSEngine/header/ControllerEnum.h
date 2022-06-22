#pragma once

//Controller 열거형
//Keyboard나 Mouse 등의 Input 클래스를 맞추기 위함
typedef enum Controller
{
	CONTROLLER_INVALID = -1,
	CONTROLLER_KEYBOARD = 0,
	CONTROLLER_MOUSE,
	CONTROLLER_NUM
}CONTROLLER;