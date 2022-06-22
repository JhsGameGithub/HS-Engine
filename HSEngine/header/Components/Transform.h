#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "MonoBehaviour.h"
#include "glm.hpp"
#include "../glm/gtx/transform.hpp"

class Transform : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(Transform, MonoBehaviour, true);

public:
	Transform();

	void SetPosition(glm::vec3 vector);
	void SetRotation(glm::vec3 vector);
	void SetScale(glm::vec3 vector);

	void Translate(glm::vec3 vector);

	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

	void UpdateWorldTransform();
	void UpdateLocalTransform();

	glm::mat4 GetWorldTransform();
	glm::mat4 GetLocalTransfrom();

	void MarkDirty();
	bool GetDirty();

	void Update() override;

private:
	glm::vec3 position, rotation, scale;
	glm::mat4 worldTransform, localTransform;
	bool dirty;
};