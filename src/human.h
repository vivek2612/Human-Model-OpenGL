#ifndef HUM_H
#define HUM_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include "tex.h"
using namespace std;

class Human{
public:
	float headx;
	float heady;
	float headz;

	float neckx;
	float necky;
	float neckz;

	float torsox;
	float torsoy;
	float torsoz;

	float leftUpperArmx;
	float leftUpperArmy;
	float leftUpperArmz;

	float rightUpperArmx;
	float rightUpperArmy;
	float rightUpperArmz;

	float leftLowerArmx;
	float rightLowerArmx;

	float hipx;
	float hipy;
	float hipz;
	float hipTranslatex;
	float hipTranslatey;
	float hipTranslatez;

	float leftUpperLegx;
	float leftUpperLegy;
	float leftUpperLegz;

	float rightUpperLegx;
	float rightUpperLegy;
	float rightUpperLegz;

	float leftLowerLegx;
	float rightLowerLegx;

	GLuint headList;
	GLuint neckList;
	GLuint torsoList;
	GLuint upperArmList;
	GLuint lowerArmList;
	GLuint hipList;
	GLuint upperLegList;
	GLuint lowerLegList;

	void createAllLists();
	void drawHuman();
	Human();


private:
	void  createHeadList();
	void  createNeckList();
	void  createTorsoList();
	void  createUpperArmList();
	void  createLowerArmList();
	void  createHipList();
	void  createUpperLegList();
	void  createLowerLegList();
	GLuint humanTexture;
};
#endif