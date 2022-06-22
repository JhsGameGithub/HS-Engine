#include "../header/RenderingMachineOpenGL.h"
#include "SDL_image.h"

void RenderingMachineOpenGL::InitRenderer()
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (double)600 / 800, 0.1, 1000);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glClearColor(0, 0, 0, 0);

	glEnable(GL_LIGHT0);
	GLfloat ambient[] = { 5,5,5,1 };
	GLfloat diffuse[] = { 1,3,3,5 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambient);

	int MatSpec[4] = { 1,1,1,1 };
	glMaterialiv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpec);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 100);

	//gluLookAt(0.0f, 0.0f, -10.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
}

void RenderingMachineOpenGL::ReadyRenderer()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderingMachineOpenGL::FinishRenderer()
{
	glFlush();
}