#pragma once

#include "../ComponentID.h"
#include "../GameObject.h"
#include "../Director.h"
#include "../Timer.h"

//��� ������Ʈ���� �θ� Ŭ����
class MonoBehaviour
{
public:
	DEFINE_COMPONENT(MonoBehaviour, null_t, true);

public:
	virtual void Awake() {}
	virtual void OnEnable() {}
	virtual void Start() {}
	virtual void FixedUpdate() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
	virtual void OnDisable() {}

protected:
	void Destroy(GameObject* obj);

public:
	MonoBehaviour();
	virtual ~MonoBehaviour();

public:
	GameObject* gameObject;
	Director& SceneManager = Director::instance();
	Timer& Time = Timer::instance();
};