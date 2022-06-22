#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/quaternion.hpp"
#include "MonoBehaviour.h"

//카메라 클래스.
//실력이 아직 미숙하여 미완성
class Camera : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(Camera, MonoBehaviour, true);
public:
    void Start() override;
    void Update() override;

    void MarkDirty();

public:
    float fovy, aspect, znear, zfar;
    glm::mat4 viewProjectionMatrix;

private:
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 forward = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 target = glm::vec3(0.0f, 0.0f, 1.0f);

    glm::vec3 position;
    glm::quat quatrotation;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::vec3 skew;
    glm::vec4 perspective;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;

    bool dirty;
};