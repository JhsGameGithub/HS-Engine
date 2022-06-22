#include <fstream>
#include <sstream>
#include <iostream>

#include "glm.hpp"
#include "../header/Components/MeshFilter.h"


MeshFilter::MeshFilter()
{
	mesh.id = 0;
	mesh.texture = 0;
}


Mesh& MeshFilter::GetMesh()
{ 
	return mesh; 
}

//삼각형에만 작동
void MeshFilter::MeshLoad(std::string name)
{
	
	mesh.id = glGenLists(1);
	mesh.boundingbox.positionMin = { 0,0,0 };
	mesh.boundingbox.positionMax = { 0,0,0 };

	glEnable(GL_TEXTURE_2D);
	std::vector<glm::vec3> temp_positions;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;
	std::vector<Face> temp_faces;
	
	std::string mtlPngFile;
	std::string line;
	std::string header;
	std::stringstream word;
	std::ifstream objectfile(path + name);
	char slash;

	if (objectfile.is_open())
	{
		while (!objectfile.eof())
		{
			word.clear();
			std::getline(objectfile, line);
			word.str(line);
			word >> header;


			switch (header[0])
			{
			case 'v':
				if (header == "vt")
				{
					glm::vec2 uv;
					word >> uv.x >> uv.y;
					temp_uvs.push_back(uv);
				}
				else if (header == "vn")
				{
					glm::vec3 normal;
					word >> normal.x >> normal.y >> normal.z;
					temp_normals.push_back(normal);
				}
				else 
				{
					glm::vec3 position;
					word >> position.x >> position.y >> position.z;
					temp_positions.push_back(position);
				}
			break;

			case 'f':
			{
				int spaces = 0;

				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ' ')
						spaces++;
				}
				
				Face face;
				unsigned int positionIndex, uvIndex, normalIndex;
				
				for (int i = 0; i < spaces; i++)
				{
					word >> positionIndex >> slash >> uvIndex >> slash >> normalIndex;
					
					face.positionIndexs.push_back(positionIndex);
					face.uvIndexs.push_back(uvIndex);
					face.normalIndexs.push_back(normalIndex);
				}
				face.vertex_num = spaces;

				temp_faces.push_back(face);
			}
			break;

			case 'm':
				word >> mtlPngFile;
				break;

			default:
				break;
			}
		}
		objectfile.close();
	}

	for (glm::vec3 position : temp_positions)
	{
		mesh.boundingbox.positionMax.x = position.x > mesh.boundingbox.positionMax.x ? position.x : mesh.boundingbox.positionMax.x;
		mesh.boundingbox.positionMax.y = position.y > mesh.boundingbox.positionMax.y ? position.y : mesh.boundingbox.positionMax.y;
		mesh.boundingbox.positionMax.z = position.z > mesh.boundingbox.positionMax.z ? position.z : mesh.boundingbox.positionMax.z;

		mesh.boundingbox.positionMin.x = position.x < mesh.boundingbox.positionMin.x ? position.x : mesh.boundingbox.positionMin.x;
		mesh.boundingbox.positionMin.y = position.y < mesh.boundingbox.positionMin.y ? position.y : mesh.boundingbox.positionMin.y;
		mesh.boundingbox.positionMin.z = position.z < mesh.boundingbox.positionMin.z ? position.z : mesh.boundingbox.positionMin.z;
	}


	
	objectfile.open(path + mtlPngFile);
	if (objectfile.is_open())
	{
		while (!objectfile.eof())
		{
			word.clear();
			std::getline(objectfile, line);
			word.str(line);
			word >> header;

			if (header[0] == 'm')
			{
				word >> mtlPngFile;
			}
		}
		objectfile.close();
		mesh.texture = LoadTexture(mtlPngFile);
	}
 
	glNewList(mesh.id, GL_COMPILE);
	if (mesh.texture != NULL)
		glBindTexture(GL_TEXTURE_2D, mesh.texture);
	glColor3b(255, 255, 255);
	for (int i = 0; i < temp_faces.size(); i++)
	{
		glBegin(temp_faces[i].vertex_num == 3 ? GL_TRIANGLES : GL_QUADS);

		for (int j = 0; j < temp_faces[i].vertex_num; j++)
		{
			glNormal3d(temp_normals[temp_faces[i].normalIndexs[j] - 1].x,
				temp_normals[temp_faces[i].normalIndexs[j] - 1].y,
				temp_normals[temp_faces[i].normalIndexs[j] - 1].z);

			glTexCoord2d(temp_uvs[temp_faces[i].uvIndexs[j] - 1].x,
						 temp_uvs[temp_faces[i].uvIndexs[j] - 1].y);

			glVertex3d(temp_positions[temp_faces[i].positionIndexs[j] - 1].x,
				temp_positions[temp_faces[i].positionIndexs[j] - 1].y,
				temp_positions[temp_faces[i].positionIndexs[j] - 1].z);
		}

		glEnd();
	}
	glEndList();
}

GLuint MeshFilter::LoadTexture(std::string filename, bool useMipMap)
{
	GLuint glID;
	SDL_Surface* picture_surface = NULL;
	SDL_Surface* gl_surface = NULL;
	SDL_Surface* gl_fliped_surface = NULL;
	Uint32 rmask, gmask, bmask, amask;
	std::string sdl_path = "resource/" + filename;

	picture_surface = IMG_Load(sdl_path.c_str());
	if (picture_surface == NULL)
		return 0;

	//엔디안 고유 값 처리하는 방식에 따라 나뉨
#if SDL_BYTEORDER == SDL_BIG_ENDIAN

	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
#else

	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif

	SDL_PixelFormat format = *(picture_surface->format);
	format.BitsPerPixel = 32;
	format.BytesPerPixel = 4;
	format.Rmask = rmask;
	format.Gmask = gmask;
	format.Bmask = bmask;
	format.Amask = amask;

	gl_surface = SDL_ConvertSurface(picture_surface, &format, SDL_SWSURFACE);

	gl_fliped_surface = flipSurface(gl_surface);

	glGenTextures(1, &glID);

	glBindTexture(GL_TEXTURE_2D, glID);

	if (useMipMap)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
			gl_fliped_surface->h, GL_RGBA, GL_UNSIGNED_BYTE,
			gl_fliped_surface->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_LINEAR);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
			gl_fliped_surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
			gl_fliped_surface->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	SDL_FreeSurface(gl_fliped_surface);
	SDL_FreeSurface(gl_surface);
	SDL_FreeSurface(picture_surface);

	return glID;
}

SDL_Surface* MeshFilter::flipSurface(SDL_Surface* surface)
{
	int current_line, pitch;
	SDL_Surface* fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
		surface->w, surface->h,
		surface->format->BitsPerPixel,
		surface->format->Rmask,
		surface->format->Gmask,
		surface->format->Bmask,
		surface->format->Amask);



	SDL_LockSurface(surface);
	SDL_LockSurface(fliped_surface);

	pitch = surface->pitch;
	for (current_line = 0; current_line < surface->h; current_line++)
	{
		memcpy(&((unsigned char*)fliped_surface->pixels)[current_line * pitch],
			&((unsigned char*)surface->pixels)[(surface->h - 1 -
				current_line) * pitch],
			pitch);
	}

	SDL_UnlockSurface(fliped_surface);
	SDL_UnlockSurface(surface);
	return fliped_surface;
}