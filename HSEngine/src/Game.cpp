#include "../header/Game.h"

Game::Game() : CurrentScene(nullptr)
{

}

void Game::RegisterScene(Scene& scene)
{
	scene_map.insert(std::make_pair(scene.scene_name, &scene));

	if (CurrentScene == nullptr)
		CurrentScene = scene_map[scene.scene_name];
}

void Game::ChangeScene(std::string name)
{
	CurrentScene = scene_map[name];
	CurrentScene->LoadScene();
}

Scene* Game::GetCurrentScene()
{
	return CurrentScene;
}