#include <Windows.h>
#include <gl/GLU.h>
#include <gl/GL.h>

#include "../header/Components/Camera.h"
#include "../header/Components/Transform.h"
#include "../glm/gtx/matrix_decompose.hpp"


void Camera::Start()
{
	fovy = glm::radians(45.0f);
	aspect = (float)600 / (float)800;
	znear = 0.1f;
	zfar = 100.0f;

	projectionMatrix = glm::perspective(fovy, aspect, znear, zfar);
}

void Camera::Update()
{
	if (dirty)
	{
		rotation = gameObject->transform->GetRotation();

		glm::decompose(gameObject->transform->GetWorldTransform(), scale, quatrotation, position, skew, perspective);

		const auto eulerRotation = glm::eulerAngles(quatrotation);

		forward = -glm::normalize(glm::vec3(
			-sin(eulerRotation.y),
			sin(eulerRotation.x) * cos(eulerRotation.y),
			cos(eulerRotation.x) * cos(eulerRotation.y)
		));

		up = glm::cross(
			glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)),
			forward
		);
		right = glm::cross(forward, up);

		right = glm::normalize(
			right * cosf(rotation.z * glm::pi<float>()) +
			up * sinf(rotation.z * glm::pi<float>())
		);
		up = glm::cross(forward, right);
		up.y = -up.y;

		target = position + forward;
		viewMatrix = glm::lookAt(position, target, up);
		viewProjectionMatrix = projectionMatrix * viewMatrix;
		
		glMatrixMode(GL_PROJECTION);
		gluLookAt(position.x, position.y, position.z, target.x, target.y, target.z, up.x, up.y, up.z);
		dirty = false;
	}
}

void Camera::MarkDirty()
{
	dirty = true;
}