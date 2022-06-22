#include <iostream>
#include <algorithm>

#include "../header/Components/MeshRenderer.h"
#include "../header/Components/MeshFilter.h"
#include "../header/GameObject.h"
#include "../header/Components/Transform.h"
#include "../glm/gtc/type_ptr.hpp"
#include "../header/Scene.h"

void MeshRenderer::Start()
{
	rendererMesh = gameObject->GetComponent<MeshFilter>()->GetMesh();
	MainCamera = gameObject->GetMyScene()->GetMainCamera();
}

void MeshRenderer::Rendering()
{
	ConvertMVP(gameObject->transform->GetWorldTransform());

	glPushMatrix();
	glMultMatrixd(mesh_transform);
	glCallList(rendererMesh.id);
	glPopMatrix();
	for (GameObject* child : gameObject->child_vector)
	{
		if (child->GetComponent<MeshRenderer>() != nullptr)
			child->GetComponent<MeshRenderer>()->Rendering();
	}
}
void MeshRenderer::ConvertMVP(glm::mat4 model)
{
	if (MainCamera != nullptr)
		ModelViewProjectionMatrix = MainCamera->viewProjectionMatrix * model;
	else
	{
		ModelViewProjectionMatrix = model;
	}

	const float* convert = (const float*)glm::value_ptr(model);

	for (int i = 0; i < 16; i++)
		mesh_transform[i] = convert[i];
}