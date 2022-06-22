#pragma once

#include "GameObject.h"
#include "Timer.h"

class ConstantFrame;
class Camera;

class Scene
{
public:
	//자신의 이름 초기화
	Scene(std::string name);

	//씬 안의 게임오브젝트 전부 메모리 해제
	~Scene();

	//씬에 게임오브젝트 추가
	void AddGameObject(GameObject& go);

	//씬의 게임오브젝트 제거
	void RemoveObject(GameObject* go);

	//씬의 메인 카메라 얻기
	Camera* GetMainCamera();

	//씬 불러오기
	void LoadScene();

	//씬 활성화
	void PlayScene(double elapsed);

	//씬 렌더링
	void RenderScene(double elapsed);

public:
	std::string scene_name;

private:
	std::vector<GameObject*> gameobject_vector;
	Timer& Time = Timer::instance();
	double physics_lag, render_lag;
	Camera* mainCamera;
};