#pragma once

#include <Windows.h>
#include <gl/GL.h>

#include "AABB3D.h"

//Mesh에 대한 정보를 담는 그릇
struct MeshStruct
{
	GLuint id;
	GLuint texture;

	AABB3D boundingbox;
}typedef Mesh;