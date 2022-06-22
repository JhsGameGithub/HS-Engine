#pragma once

#include "../AABB3D.h"
#include "MonoBehaviour.h"

class CollisionAABB : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(CollisionAABB, MonoBehaviour, true);

public:
	//Mesh���� BoundingBox�� ������
	void Start() override;
	
	//TargetBox�� ���� �浹�ڽ��� �浹üũ
	bool CollisionCheck();

	void SetTargetObject(GameObject* targetObj);
private:
	AABB3D m_BoundingBox;
	AABB3D m_TargetBox;
	Transform* m_targetTransform;
};