#pragma once

//������ ��ü�� ���� �������̽�
class RenderingMachine
{
public:
	virtual void InitRenderer() = 0;
	virtual void ReadyRenderer() = 0;
	virtual void FinishRenderer() = 0;
};