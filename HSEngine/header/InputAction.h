#pragma once

#include <string>

#include "GameObject.h"
#include "ControllerEnum.h"

//��� Input���� �߻�Ŭ����(MouseMoving ����)
class InputAction
{
public:
	//�Է��� ������ ��
	virtual void BeginInput() = 0;
	//�Է��� ������ ��
	virtual void HoldInput() = 0;
	//�Է��� ���� ��
	virtual void EndInput() = 0;
	
	//Ű �ڵ� ��ȯ
	unsigned int GetInput();
	//�ڽ��� ��ġ ��ȯ
	CONTROLLER GetController();
	//���� ������ ���� �ڽ��� ���� ������Ʈ ��������
	void SetGameObject(GameObject* obj);

protected:
	InputAction(unsigned int code, CONTROLLER control);
	GameObject* gameObject;

private:
	unsigned int myInput;
	CONTROLLER m_controller;
};

