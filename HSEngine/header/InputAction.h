#pragma once

#include <string>

#include "GameObject.h"
#include "ControllerEnum.h"

//모든 Input들의 추상클래스(MouseMoving 제외)
class InputAction
{
public:
	//입력을 시작할 때
	virtual void BeginInput() = 0;
	//입력을 유지할 때
	virtual void HoldInput() = 0;
	//입력을 끝낼 때
	virtual void EndInput() = 0;
	
	//키 코드 반환
	unsigned int GetInput();
	//자신의 장치 반환
	CONTROLLER GetController();
	//로직 접근을 위한 자신의 게임 오브젝트 가져오기
	void SetGameObject(GameObject* obj);

protected:
	InputAction(unsigned int code, CONTROLLER control);
	GameObject* gameObject;

private:
	unsigned int myInput;
	CONTROLLER m_controller;
};

