#pragma once

#include <string>

class Game;

//������ Ŭ����
//�̱����̸� ������ ������
class Director
{
public:
	//�̱��� ����, ��ü�� �ϳ����� ����
	static Director& instance() 
	{
		static Director instance;
		return instance;
	}

public:
	//�� �ٲٱ�
	void ChangeScene(std::string name);

	//���� ���
	void SetGame(Game* game);

private:
	Director();

	Director(const Director&) = delete;

	void operator=(const Director&) = delete;
	
private:
	Game* pGame;
};