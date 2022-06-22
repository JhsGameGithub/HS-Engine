#pragma once

#include <string>
#include <map>

#include "Scene.h"

//Engine들의 추상클래스
class Game
{
public:
	Game();

	void RegisterScene(Scene& scene);

	void ChangeScene(std::string name);

	Scene* GetCurrentScene();

	virtual void Run() = 0;

	virtual bool InitGame() = 0;
	
	virtual void InitRenderer() = 0;

	virtual void Terminate() = 0;

	virtual ~Game() {};

protected:
	Scene* CurrentScene;

private:
	std::map<std::string, Scene*> scene_map;
};