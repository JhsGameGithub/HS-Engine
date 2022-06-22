#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "ComponentID.h"

class MonoBehaviour;
class Transform;
class Scene;

//Object 클래스.
//참조자를 이용하여 포인터가 아닌 객체를 강제
class GameObject
{
public:
	//게임 오브젝트의 이름 지정 및 초기화
	GameObject(std::string name);

	//컴포넌트 맵에 동적 할당된 메모리 해제
	~GameObject();

	//자식 오브젝트 추가
	void addChild(GameObject child);

	//부모 오브젝트 초기화
	void setParents(GameObject parents);

	//자신이 몸 담고 있는 씬 반환
	Scene* GetMyScene();

	//자신이 몸 담고 있는 씬 가져오기
	void SetMyScene(Scene* scene);

	//자신의 부모 오브젝트 반환
	GameObject* getParents();

	//게임 오브젝트 이름 반환
	std::string getGameObjectName();

	//컴포넌트 추가
	template<class T>
	void AddComponent(T* component)
	{
		size_t componentId = get_component<T>::type::getComponentId();

		this->component_map[componentId] = component;
		this->component_map[componentId]->gameObject = this;
	}

	//컴포넌트 반환
	template<class T>
	T* GetComponent(void)
	{
		size_t componentId = get_component<T>::type::getComponentId();

		if (this->component_map.find(componentId) == this->component_map.end())
			return nullptr;

		return reinterpret_cast<T*>(this->component_map[componentId]);
	}

	//컴포넌트들의 로직 실행//
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