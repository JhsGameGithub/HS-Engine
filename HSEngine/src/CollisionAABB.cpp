#include "../header/Components/CollisionAABB.h"
#include "../header/Components/MeshFilter.h"
#include "../header/Components/Transform.h"

void CollisionAABB::Start()
{
	m_BoundingBox = gameObject->GetComponent<MeshFilter>()->GetMesh().boundingbox;
}

bool CollisionAABB::CollisionCheck()
{
	if (
		m_BoundingBox.positionMin.x + gameObject->transform->GetPosition().x <= m_TargetBox.positionMax.x + m_targetTransform->GetPosition().x &&
		m_BoundingBox.positionMax.x + gameObject->transform->GetPosition().x >= m_TargetBox.positionMin.x + m_targetTransform->GetPosition().x &&
		m_BoundingBox.positionMin.y + gameObject->transform->GetPosition().y <= m_TargetBox.positionMax.y + m_targetTransform->GetPosition().y &&
		m_BoundingBox.positionMax.y + gameObject->transform->GetPosition().y >= m_TargetBox.positionMin.y + m_targetTransform->GetPosition().y &&
		m_BoundingBox.positionMin.z + gameObject->transform->GetPosition().z <= m_TargetBox.positionMax.z + m_targetTransform->GetPosition().z &&
		m_BoundingBox.positionMax.z + gameObject->transform->GetPosition().z >= m_TargetBox.positionMin.z + m_targetTransform->GetPosition().z
		)
	{
		return true;
	}

	return false;
}


void CollisionAABB::SetTargetObject(GameObject* targetObj)
{
	m_TargetBox = targetObj->GetComponent<MeshFilter>()->GetMesh().boundingbox;
	m_targetTransform = targetObj->transform;
}