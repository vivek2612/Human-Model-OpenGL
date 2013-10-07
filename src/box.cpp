#include "box.h"

 Box::Box(){
 	lidAngle=0.0f;
}

void Box::createQuadList(){
	
	boxSize=2.0f;
   	
   	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	quadList=glGenLists (1);
	glNewList(quadList, GL_COMPILE);
		Texture tex;
		boxTexture = tex.loadBMP_custom("./images/wood2.bmp");
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f( boxSize,-boxSize,boxSize);
		    glTexCoord2f(0.0, 1.0); glVertex3f( boxSize, boxSize,boxSize);
		    glTexCoord2f(1.0, 1.0); glVertex3f(-boxSize, boxSize,boxSize);
		    glTexCoord2f(1.0, 0.0); glVertex3f(-boxSize, -boxSize,boxSize);        
		glEnd();
	glEndList();
}

void Box::drawBox(){

	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
		glCallList(quadList);
		glPushMatrix();
			glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
			glCallList(quadList);
		glPopMatrix();
		glPushMatrix();
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glCallList(quadList);
		glPopMatrix();
		glPushMatrix();
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			glCallList(quadList);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glCallList(quadList);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-boxSize, boxSize, 0.0f);
			glRotatef(lidAngle, 0.f, 0.0f, boxSize);
			glTranslatef(boxSize, -boxSize, 0.0f);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
			glCallList(quadList);
		glPopMatrix();
	glPopMatrix();	
}