#ifndef TEX_H
#define TEX_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Texture{
public:
	GLuint loadBMP_custom(const char * imagepath);
};

#endif

