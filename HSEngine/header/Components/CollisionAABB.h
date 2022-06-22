#pragma once

#include "../AABB3D.h"
#include "MonoBehaviour.h"

class CollisionAABB : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(CollisionAABB, MonoBehaviour, true);

public:
	//Mesh에서 BoundingBox를 가져옴
	void Start() override;
	
	//TargetBox와 나의 충돌박스의 충돌체크
	bool CollisionCheck();

	void SetTargetObject(GameObject* targetObj);
private:
	AABB3D m_BoundingBox;
	AABB3D m_TargetBox;
	Transform* m_targetTransform;
};