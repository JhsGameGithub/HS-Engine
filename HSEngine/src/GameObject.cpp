#include "../header/GameObject.h"
#include "../header/Components/Renderer.h"
#include "../header/Components/Transform.h"

//처음부터 끝까지 할당된 메모리 삭제하거나
//같은 함수만을 호출하므로 범위기반 for문 사용

GameObject::GameObject(std::string name) : gameobject_name(name), parents_gameobject(nullptr)
{
	this->AddComponent(new Transform);
	transform = this->GetComponent<Transform>();
}

GameObject::~GameObject()
{
	for (auto component : component_map)
	{
		delete component.second;
	}
	component_map.clear();
	child_vector.clear();

	delete parents_gameobject;
}

void GameObject::addChild(GameObject child)
{
	child.setParents(*this);
	child_vector.push_back(&child);
}

void GameObject::setParents(GameObject parents)
{
	parents_gameobject = &parents;
}

GameObject* GameObject::getParents()
{
	if (parents_gameobject == nullptr)
		return nullptr;
	return parents_gameobject;
}


Scene* GameObject::GetMyScene()
{
	return m_scene;
}
void GameObject::SetMyScene(Scene* scene)
{
	m_scene = scene;
}


std::string GameObject::getGameObjectName()
{
	return gameobject_name;
}

void GameObject::ComponentsAwake()
{
	for (auto component : component_map)
	{
		component.second->Awake();
	}
}

void GameObject::ComponentsStart()
{
	for (auto component : component_map)
	{
		component.second->Start();
	}
}

void GameObject::ComponentsUpdate()
{
	for (auto component : component_map)
	{
		component.second->Update();
	}
}

void GameObject::ComponentsLateUpdate()
{
	for (auto component : component_map)
	{
		component.second->LateUpdate();
	}
}

void GameObject::ComponentsFixedUpdate()
{
	for (auto component : component_map)
	{
		component.second->FixedUpdate();
	}
}

void GameObject::GameObjectRender()
{
	if (GetComponent<Renderer>() == nullptr)
		return;

	GetComponent<Renderer>()->Rendering();
}