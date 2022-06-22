#include "../header/Components/MonoBehaviour.h"
#include "../header/Scene.h"

MonoBehaviour::MonoBehaviour()
{
	gameObject = nullptr;
}

MonoBehaviour::~MonoBehaviour()
{
	delete gameObject;
}

void MonoBehaviour::Destroy(GameObject* obj)
{
	gameObject->GetMyScene()->RemoveObject(obj);
}