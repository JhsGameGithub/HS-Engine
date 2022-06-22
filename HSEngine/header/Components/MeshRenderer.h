#pragma once

#include "Renderer3D.h"
#include "../MeshStruct.h"
#include "glm.hpp"
#include "Camera.h"

//obj ������ ���������� �׸��� ������Ʈ
class MeshRenderer : public Renderer3D
{
public:
	DEFINE_COMPONENT(MeshRenderer, Renderer3D, false);

public:
	void Start() override;
	void Rendering() override;
	void ConvertMVP(glm::mat4 model);

private:
	Mesh rendererMesh;
	GLdouble mesh_transform[16];
	glm::mat4 ModelViewProjectionMatrix;
	Camera* MainCamera;
};