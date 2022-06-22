#pragma once

#include "Renderer3D.h"
#include "../MeshStruct.h"
#include "glm.hpp"
#include "Camera.h"

//obj 파일을 실질적으로 그리는 컴포넌트
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