#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "ComponentID.h"

class MonoBehaviour;
class Transform;
class Scene;

//Object Ŭ����.
//�����ڸ� �̿��Ͽ� �����Ͱ� �ƴ� ��ü�� ����
class GameObject
{
public:
	//���� ������Ʈ�� �̸� ���� �� �ʱ�ȭ
	GameObject(std::string name);

	//������Ʈ �ʿ� ���� �Ҵ�� �޸� ����
	~GameObject();

	//�ڽ� ������Ʈ �߰�
	void addChild(GameObject child);

	//�θ� ������Ʈ �ʱ�ȭ
	void setParents(GameObject parents);

	//�ڽ��� �� ��� �ִ� �� ��ȯ
	Scene* GetMyScene();

	//�ڽ��� �� ��� �ִ� �� ��������
	void SetMyScene(Scene* scene);

	//�ڽ��� �θ� ������Ʈ ��ȯ
	GameObject* getParents();

	//���� ������Ʈ �̸� ��ȯ
	std::string getGameObjectName();

	//������Ʈ �߰�
	template<class T>
	void AddComponent(T* component)
	{
		size_t componentId = get_component<T>::type::getComponentId();

		this->component_map[componentId] = component;
		this->component_map[componentId]->gameObject = this;
	}

	//������Ʈ ��ȯ
	template<class T>
	T* GetComponent(void)
	{
		size_t componentId = get_component<T>::type::getComponentId();

		if (this->component_map.find(componentId) == this->component_map.end())
			return nullptr;

		return reinterpret_cast<T*>(this->component_map[componentId]);
	}

	//������Ʈ���� ���� ����//
	void ComponentsAwake();
	void ComponentsStart();
	void ComponentsUpdate();
	void ComponentsLateUpdate();
	void ComponentsFixedUpdate();
	void GameObjectRender();

public:
	std::vector<GameObject*> child_vector;
	std::string gameobject_name;
	Transform* transform;

private:
	std::unordered_map<size_t,MonoBehaviour*> component_map;
	GameObject* parents_gameobject;
	Scene* m_scene;
};