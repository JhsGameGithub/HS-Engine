#include <Windows.h>
#include <gl/GL.h>

#include "../header/Scene.h"
#include "../header/Components/Camera.h"

Scene::Scene(std::string name) : scene_name(name), physics_lag(0), render_lag(0)
{
}

Scene::~Scene()
{
	gameobject_vector.clear();
}

void Scene::AddGameObject(GameObject& gameobject)
{
	gameobject_vector.push_back(&gameobject);
	gameobject.SetMyScene(this);
}

void Scene::RemoveObject(GameObject* go)
{
	for (std::vector<GameObject*>::iterator it = gameobject_vector.begin();
		it != gameobject_vector.end();
		it++)
	{
		if ((*it) == go)
		{
			gameobject_vector.erase(it);
			break;
		}
	}
}

Camera* Scene::GetMainCamera()
{
	return mainCamera;
}


void Scene::LoadScene()
{
	for (GameObject* gameobject : gameobject_vector)
	{
		gameobject->ComponentsAwake();
		if (gameobject->GetComponent<Camera>() != nullptr)
			mainCamera = gameobject->GetComponent<Camera>();
	}

	for (GameObject* gameobject : gameobject_vector)
	{
		gameobject->ComponentsStart();
	}
}

void Scene::PlayScene(double elapsed)
{
	physics_lag += elapsed;

	//1ÃÊ¿¡ 15¹ø
	while (physics_lag >= (double)Time.getFrequency().QuadPart / 15)
	{
		for (GameObject* gameobject : gameobject_vector)
		{
			gameobject->ComponentsFixedUpdate();
		}
		physics_lag -= (double)Time.getFrequency().QuadPart / 15;
	}

	for (GameObject* gameobject : gameobject_vector)
	{
		gameobject->ComponentsUpdate();
	}

	for (GameObject* gameobject : gameobject_vector)
	{
		gameobject->ComponentsLateUpdate();
	}
}

void Scene::RenderScene(double elapsed)
{
	render_lag += elapsed;

	while (render_lag >= (double)Time.getFrequency().QuadPart / 60)
	{
		for (GameObject* gameobject : gameobject_vector)
		{
			gameobject->GameObjectRender();
		}
		render_lag -= (double)Time.getFrequency().QuadPart / 60;
	}
}