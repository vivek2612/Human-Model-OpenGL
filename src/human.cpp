
#include "human.h"

void  Human::createHeadList(){
	headList=glGenLists (1);
	glNewList(headList, GL_COMPILE);
	glPushMatrix();
		glScalef(0.9f,1.0f,1.0f);
		Texture tex;
		// humanTexture = tex.loadBMP_custom("./images/face.bmp");
		glColor3f(0.0f, 1.0f, 0.2f);    
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		gluQuadricTexture(quadratic,1);
		gluSphere(quadratic,1.3f,32,32);
	glPopMatrix();
	glEndList();
}

void Human::createNeckList(){
	
	neckList=glGenLists (1);
	glNewList(neckList, GL_COMPILE);
		Texture tex;
		humanTexture = tex.loadBMP_custom("./images/wood.bmp");
		glColor3f(1.0f, 0.8f, 0.2f);    
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,0.6f,0.6f,0.6f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();

}

void Human::createTorsoList(){
	torsoList=glGenLists (1);
	glNewList(torsoList, GL_COMPILE);
		Texture tex;
		humanTexture = tex.loadBMP_custom("./images/shirt.bmp");
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,2.5f,2.0f,5.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Human::createUpperArmList(){
	upperArmList=glGenLists (1);
	glNewList(upperArmList, GL_COMPILE);
		Texture tex;
		humanTexture = tex.loadBMP_custom("./images/shirt.bmp");
		glColor3f(0.0f, 1.0f, 0.2f);    
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,0.6f,0.6f,3.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Human::createLowerArmList(){
	lowerArmList=glGenLists (1);
	glNewList(lowerArmList, GL_COMPILE);
		glColor3f(0.0f, 1.0f, 0.8f);    
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,0.6f,0.4f,4.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Human::createHipList(){
    hipList=glGenLists (1);
	glNewList(hipList, GL_COMPILE);
		Texture tex;
		humanTexture = tex.loadBMP_custom("./images/belt.bmp");
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,2.1f,2.1f,1.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Human::createUpperLegList(){
	upperLegList=glGenLists (1);
	glNewList(upperLegList, GL_COMPILE);
		Texture tex;
		humanTexture = tex.loadBMP_custom("./images/trouser.bmp");
		glColor3f(1.0f, 1.0f, 0.0f);    
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,1.0f,1.0f,4.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Human::createLowerLegList(){
	lowerLegList=glGenLists (1);
	glNewList(lowerLegList, GL_COMPILE);
		Texture tex;
		humanTexture = tex.loadBMP_custom("./images/trouser.bmp");
		glColor3f(0.0f, 1.0f, 0.8f);    
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic,1);
		gluCylinder(quadratic,1.0f,0.8f,6.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Human::createAllLists(){
	createHeadList();
	createNeckList();
	createTorsoList();
	createUpperArmList();
	createLowerArmList();
	createHipList();
	createUpperLegList();
	createLowerLegList();
}

void Human::drawHuman(){
	glPushMatrix();
		
		// hip
		glTranslatef(hipTranslatex,hipTranslatey,hipTranslatez);
		glTranslatef(0.0f, -1.0f, 0.0f);
		glRotatef(hipx,1.0,0.0,0.0);
		glRotatef(hipz,0.0,0.0,1.0);
		glRotatef(hipy,0.0,1.0,0.0);
		glTranslatef(0.0f, 1.0f, 0.0f);
		glCallList(hipList);
		glPushMatrix();
			glTranslatef(-1.1f,-1.0f,0.0f);
			glRotatef(leftUpperLegx,1.0,0.0,0.0);
			glRotatef(leftUpperLegz,0.0,0.0,1.0);
			glRotatef(leftUpperLegy,0.0,1.0,0.0);
			glCallList(upperLegList);															
			glTranslatef(0.0f,-4.0f,0.0f);
			glRotatef(leftLowerLegx,1.0,0.0,0.0);
			glCallList(lowerLegList);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.1f,-1.0f,0.0f);
			glRotatef(rightUpperLegx,1.0,0.0,0.0);
			glRotatef(rightUpperLegz,0.0,0.0,1.0);
			glRotatef(rightUpperLegy,0.0,1.0,0.0);
			glCallList(upperLegList);
			glTranslatef(0.0f,-4.0f,0.0f);
			glRotatef(rightLowerLegx,1.0,0.0,0.0);
			glCallList(lowerLegList);
		glPopMatrix();

		glRotatef(torsox,1.0,0.0,0.0);
		glRotatef(torsoz,0.0,0.0,1.0);
		glRotatef(torsoy,0.0,1.0,0.0);
		glTranslatef(0.0f, 5.0f, 0.0f);
		glCallList(torsoList);

		glPushMatrix();
			glTranslatef(2.5f,-0.0f,0.0f);
			glRotatef(rightUpperArmx,1.0,0.0,0.0);
			glRotatef(rightUpperArmz,0.0,0.0,1.0);
			glRotatef(rightUpperArmy,0.0,1.0,0.0);
			glCallList(upperArmList);

			glTranslatef(0.0,-3.0f,0.0f);
			glRotatef(rightLowerArmx,1.0,0.0,0.0f);
			glCallList(lowerArmList);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.5f,-0.0f,0.0f);
			glRotatef(leftUpperArmx,1.0,0.0,0.0);
			glRotatef(leftUpperArmz,0.0,0.0,1.0);
			glRotatef(leftUpperArmy,0.0,1.0,0.0);
			glCallList(upperArmList);

			glTranslatef(0.0,-3.0f,0.0f);
			glRotatef(leftLowerArmx,1.0,0.0,0.0f);
			glCallList(lowerArmList);
		glPopMatrix();

		
		glRotatef(neckx,1.0,0.0,0.0);
		glRotatef(neckz,0.0,0.0,1.0);
		glRotatef(necky,0.0,1.0,0.0);
		glTranslatef(0.0f,0.6f,0.0f);
		glCallList(neckList);

		glRotatef(headx,1.0,0.0,0.0);
		glRotatef(headz,0.0,0.0,1.0);
		glRotatef(heady,0.0,1.0,0.0);
		glTranslatef(0.0f,1.3f,0.0f);
		glCallList(headList);


	glPopMatrix();
}


Human::Human(){
	headx=0.0f;
	heady=0.0f;
	headz=0.0f;

	neckx=0.0f;
	necky=0.0f;
	neckz=0.0f;

	torsox=0.0f;
	torsoy=0.0f;
	torsoz=0.0f;

	leftUpperArmx=0.0f;
	leftUpperArmy=0.0f;
	leftUpperArmz=-10.0f;

	rightUpperArmx=0.0f;
	rightUpperArmy=0.0f;
	rightUpperArmz=10.0f;

	leftLowerArmx=-10.0f;
	rightLowerArmx=-50.0f;

	hipx=0.0f;
	hipy=0.0f;
	hipz=0.0f;
	hipTranslatex=0.0f;
	hipTranslatey=0.0f;
	hipTranslatez=0.0f;

	leftUpperLegx=0.0f;
	leftUpperLegy=0.0f;
	leftUpperLegz=-5.0f;

	rightUpperLegx=0.0f;
	rightUpperLegy=0.0f;
	rightUpperLegz=5.0f;

	leftLowerLegx=0.0f;
	rightLowerLegx=0.0f;
}

void Human::reset(){
	headx=0.0f;
	heady=0.0f;
	headz=0.0f;

	neckx=0.0f;
	necky=0.0f;
	neckz=0.0f;

	torsox=0.0f;
	torsoy=0.0f;
	torsoz=0.0f;

	leftUpperArmx=0.0f;
	leftUpperArmy=0.0f;
	leftUpperArmz=-10.0f;

	rightUpperArmx=0.0f;
	rightUpperArmy=0.0f;
	rightUpperArmz=10.0f;

	leftLowerArmx=-10.0f;
	rightLowerArmx=-50.0f;

	hipx=0.0f;
	hipy=0.0f;
	hipz=0.0f;
	hipTranslatex=0.0f;
	hipTranslatey=0.0f;
	hipTranslatez=0.0f;

	leftUpperLegx=0.0f;
	leftUpperLegy=0.0f;
	leftUpperLegz=-5.0f;

	rightUpperLegx=0.0f;
	rightUpperLegy=0.0f;
	rightUpperLegz=5.0f;

	leftLowerLegx=0.0f;
	rightLowerLegx=0.0f;
}