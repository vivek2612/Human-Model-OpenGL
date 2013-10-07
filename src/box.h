#ifndef BOX_H
#define BOX_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "tex.h"
using namespace std;

class Box{
public:
	GLuint quadList;
	void createQuadList();
	void drawBox();
	float lidAngle;
	Box();
private:
	GLuint boxTexture;
	float boxSize;
};

#endif