#pragma once

#include <vector>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <filesystem>

#include "SDL.h"
#include "SDL_image.h"
#include "../MeshStruct.h"
#include "MonoBehaviour.h"
#include "../FaceStruct.h"
#include "glm.hpp"

//Obj 가져오고 관리하는 클래스
class MeshFilter : public MonoBehaviour
{
public:
	DEFINE_COMPONENT(MeshFilter, MonoBehaviour, true);
public:
	MeshFilter();

	void MeshLoad(std::string name);

	Mesh& GetMesh();

	SDL_Surface* flipSurface(SDL_Surface* surface);

	GLuint LoadTexture(std::string filename, bool useMipMap = true);

private:
	Mesh mesh;
	std::string path = std::filesystem::current_path().string() + "\\resource\\";
};