#pragma once

#include <string>

class Game;

//감독관 클래스
//싱글톤이며 쓰레드 안전함
class Director
{
public:
	//싱글톤 패턴, 객체가 하나임을 보장
	static Director& instance() 
	{
		static Director instance;
		return instance;
	}

public:
	//씬 바꾸기
	void ChangeScene(std::string name);

	//게임 등록
	void SetGame(Game* game);

private:
	Director();

	Director(const Director&) = delete;

	void operator=(const Director&) = delete;
	
private:
	Game* pGame;
};