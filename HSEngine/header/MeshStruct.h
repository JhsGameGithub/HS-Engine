#pragma once

#include <Windows.h>
#include <gl/GL.h>

#include "AABB3D.h"

//Mesh�� ���� ������ ��� �׸�
struct MeshStruct
{
	GLuint id;
	GLuint texture;

	AABB3D boundingbox;
}typedef Mesh;