#pragma once

#include "glm.hpp"

//AABB 충돌박스
struct AABB3DStruct
{
	glm::vec3 positionMin;
	glm::vec3 positionMax;
}typedef AABB3D;