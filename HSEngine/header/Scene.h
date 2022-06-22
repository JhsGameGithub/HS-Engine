#pragma once

#include "GameObject.h"
#include "Timer.h"

class ConstantFrame;
class Camera;

class Scene
{
public:
	//�ڽ��� �̸� �ʱ�ȭ
	Scene(std::string name);

	//�� ���� ���ӿ�����Ʈ ���� �޸� ����
	~Scene();

	//���� ���ӿ�����Ʈ �߰�
	void AddGameObject(GameObject& go);

	//���� ���ӿ�����Ʈ ����
	void RemoveObject(GameObject* go);

	//���� ���� ī�޶� ���
	Camera* GetMainCamera();

	//�� �ҷ�����
	void LoadScene();

	//�� Ȱ��ȭ
	void PlayScene(double elapsed);

	//�� ������
	void RenderScene(double elapsed);

public:
	std::string scene_name;

private:
	std::vector<GameObject*> gameobject_vector;
	Timer& Time = Timer::instance();
	double physics_lag, render_lag;
	Camera* mainCamera;
};