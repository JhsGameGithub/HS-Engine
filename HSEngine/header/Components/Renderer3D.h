#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Renderer.h"

//3D ���������� ���� �߰� �θ� Ŭ����
class Renderer3D :public Renderer
{
public:
	DEFINE_COMPONENT(Renderer3D, Renderer, false);

public:
	void Rendering() override {};
	virtual ~Renderer3D() {};
};