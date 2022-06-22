#pragma once

#include <string>

#include "MonoBehaviour.h"

//Interface
class Renderer : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(Renderer, MonoBehaviour, true);

public:
	virtual void Rendering() = 0;
};