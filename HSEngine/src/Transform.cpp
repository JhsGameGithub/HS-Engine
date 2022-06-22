#include "../header/Components/Transform.h"
#include "../header/Components/Camera.h"

Transform::Transform() : dirty(true)
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);

	worldTransform = glm::mat4(1.0f);
	localTransform = glm::mat4(1.0f);
}

void Transform::UpdateWorldTransform()
{
	if (dirty)
	{
		if (gameObject->GetComponent<Camera>() != nullptr)
			gameObject->GetComponent<Camera>()->MarkDirty();

		this->UpdateLocalTransform();
		if (gameObject->getParents() != nullptr)
		{
			worldTransform = gameObject->getParents()->transform->GetWorldTransform() * localTransform;
		}
		else
		{
			worldTransform = glm::mat4(1.0f) * localTransform;
		}

		dirty = false;
		for (GameObject* children : gameObject->child_vector)
		{
			children->transform->MarkDirty();
			children->transform->UpdateWorldTransform();
		}
	}
	else
	{
		for (GameObject* children : gameObject->child_vector)
		{
			children->transform->UpdateWorldTransform();
		}
	}
}

void Transform::Update()
{
	UpdateWorldTransform();
}

void Transform::UpdateLocalTransform()
{
	if (dirty)
	{
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, position);
		transform = glm::rotate(transform, rotation.y, glm::vec3(0.0, 1.0, 0.0));
		transform = glm::rotate(transform, rotation.x, glm::vec3(1.0, 0.0, 0.0));
		transform = glm::rotate(transform, rotation.z, glm::vec3(0.0, 0.0, 1.0));
		transform = glm::scale(transform, scale);
		localTransform = transform;
	}
}

void Transform::MarkDirty()
{
	dirty = true;
}

bool Transform::GetDirty()
{
	return dirty;
}

void Transform::SetPosition(glm::vec3 vector)
{
	dirty = true;
	position = vector;
}

void Transform::SetRotation(glm::vec3 vector)
{
	dirty = true;
	rotation = vector;
}

void Transform::SetScale(glm::vec3 vector)
{
	dirty = true;
	scale = vector;
}

void Transform::Translate(glm::vec3 vector)
{
	dirty = true;
	position += vector;
}


glm::vec3 Transform::GetPosition()
{
	return position;
}
glm::vec3 Transform::GetRotation()
{
	return rotation;
}
glm::vec3 Transform::GetScale()
{
	return scale;
}

glm::mat4 Transform::GetWorldTransform()
{
	return worldTransform;
}

glm::mat4 Transform::GetLocalTransfrom()
{
	return localTransform;
}