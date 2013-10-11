
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>
#include <cstdio>
#include "box.h"
#include "human.h"

#define _USE_MATH_DEFINES

/* Global variables */
char title[] = "3D Shapes";
float degree = 0.0f;
float verticalDegree = 0.0f;
Box boxObject;



float eyex=0.0f,eyey=0.0f,eyez=0.0f;
Human humanObject;
int mode = -1;
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   humanObject.createAllLists();
   boxObject.createQuadList();
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   gluLookAt(eyex, eyey, eyez, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
   glLoadIdentity();
   glTranslatef( 0.0f, 0.0f, -20.0f);
   glRotatef(degree, 0.0f, 1.0f, 0.0f);
   glRotatef(verticalDegree, 1.0f, 0.0f, 0.0f);
   
   glColor3f(1.0f, 1.0f, 1.0f);   
   
   humanObject.drawHuman();
   glTranslatef(5.0f,0.0f,15.0f);
   
   boxObject.drawBox();
   glDisable(GL_TEXTURE_2D);
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(60.0f, aspect, 0.1f, 100.0f);
}
 
void mouse(int button, int state, int x, int y){
    glutPostRedisplay();
}

void inputKey(int key, int x, int y){
   switch(key){
      case GLUT_KEY_LEFT : degree -= 1.0f;break;
      case GLUT_KEY_RIGHT : degree += 1.0f;break;
   }
}

/*Body movement scheme is designed in the following way
There are modes which designate which body part's degree of freedom are controlled by the keys 'z', 'x' and 'c'
Mode Index :
	0: Hip-Translation
	1: Head
	2: Neck
	3: Torso
	4: Left-Upper-Arm
	5: Left-Lower-Arm
	6: Right-Upper-Arm
	7: Right-Lower-Arm
	8: Hip
	'p': Left-Upper-Leg
	'o': Left-Lower-Leg
	'i': Right-Upper-Leg
	'u': Right-Lower-Leg

If key 'z' would would increase a certain parameter of movement of some joint 'Shift'+'z' or 'Z' would decrease it

Other than that the box lid angle is controlled by '=' and '-'

All joints and box-lid have certain boundaries till which they can rotate in various directions

Also w, s, a & d control the camera
*/



void keyboard(unsigned char key, int x, int y){
   switch(key){
      case 27:
      {
         exit(0);
         break;
      }
      case '0':{
  		mode = 0;
	    glutPostRedisplay();
	    break;
      }
      case '1':{
  		mode = 1;
	    glutPostRedisplay();
	    break;
      }
      case '2':{
  		mode = 2;
	    glutPostRedisplay();
	    break;
      }
      case '3':{
  		mode = 3;
	    glutPostRedisplay();
	    break;
      }
      case '4':{
  		mode = 4;
	    glutPostRedisplay();
	    break;
      }
      case '5':{
  		mode = 5;
	    glutPostRedisplay();
	    break;
      }
      case '6':{
  		mode = 6;
	    glutPostRedisplay();
	    break;
      }
      case '7':{
  		mode = 7;
	    glutPostRedisplay();
	    break;
      }
      case '8':{
  		mode = 8;
	    glutPostRedisplay();
	    break;
      }
      case 'p':{
  		mode = 9;
	    glutPostRedisplay();
	    break;
      }
      case 'o':{
  		mode = 10;
	    glutPostRedisplay();
	    break;
      }
      case 'i':{
  		mode = 11;
	    glutPostRedisplay();
	    break;
      }
      case 'u':{
  		mode = 12;
	    glutPostRedisplay();
	    break;
      }
      case '=':
      {
         boxObject.lidAngle+=1.0f;
         glutPostRedisplay();
         break;
      }
      case '-':
      {
         boxObject.lidAngle-=1.0f;
         glutPostRedisplay();
         break;
      }
      case 'a':
      {
         degree-=5.0f;
         glutPostRedisplay();
         break;
      }
      case 'd':
      {
         degree+=5.0f;
         glutPostRedisplay();
         break;
      }
      case 'w':
      {
         verticalDegree-=3.0f;
         // eyez-=0.1f;
         glutPostRedisplay();
         break;
      }
      case 's':
      {
         verticalDegree+=3.0f;
         // eyez+=10.1f;
         glutPostRedisplay();
         break;
      }
      case 'z':{
  		if(mode>=0){
  			if(mode == 0){
  				//Hip Translation
  				humanObject.hipTranslatez += 0.1f;
  			}
  			else if (mode == 1){
  				// Head Rotation
  				if(humanObject.headz <= 45.0f)
  					humanObject.headz += 2.0f;
  			}
  			else if (mode == 2){
  				// Neck Rotation
  				if(humanObject.neckz <= 25.0f)
  					humanObject.neckz += 2.0f;
  			}
  			else if (mode == 3){
  				// Torso Rotation
  				if(humanObject.torsoz <= 25.0f)
  					humanObject.torsoz += 2.0f;
  			}
  			else if (mode == 4){
  				if((((int)humanObject.leftUpperArmx)%360 <= 20.0f || ((int)humanObject.leftUpperArmx)%360 >= 340.0f) && humanObject.leftUpperArmy >= 10.0f){
  					/*cout<<"problem case"<<endl;
  					cout<<"angle"<<":"<<4.0/7.0*humanObject.leftLowerArmx<<endl;*/
  					if(humanObject.leftUpperArmz < 0.0f && humanObject.leftUpperArmz < 4.0/7.0*humanObject.leftLowerArmx ){
  						humanObject.leftUpperArmz+=2.0f;
            }
  				}else{
  					if(humanObject.leftUpperArmz < 0.0f)
  						humanObject.leftUpperArmz += 2.0f;
  				}
  			}
  			else if (mode == 6){
  				if(humanObject.rightUpperArmz<180.0f)
  					humanObject.rightUpperArmz+=2.0f;
  			}
  			else if(mode == 8){
  				if(humanObject.hipz < 45.0f)
  					humanObject.hipz += 2.0f;
  			}
  			else if(mode == 9){
  				if(humanObject.leftUpperLegz < 0.0f)
  					humanObject.leftUpperLegz += 2.0f;
  			}
  			else if(mode == 11){
  				if(humanObject.rightUpperLegz < 45.0f)
  					humanObject.rightUpperLegz += 2.0f;
  			}
  		}
	    glutPostRedisplay();
	    break;
      }
      case 'Z':{
  		if(mode>=0){
  			if(mode == 0){
  				//Hip Translation
  				humanObject.hipTranslatez -= 0.1f;
  			}
  			else if (mode == 1){
  				// Head Rotation
  				if(humanObject.headz >= -45.0f)
  					humanObject.headz -= 2.0f;
  			}
  			else if (mode == 2){
  				// Neck Rotation
  				if(humanObject.neckz >= -25.0f)
  					humanObject.neckz -= 2.0f;
  			}
  			else if (mode == 3){
  				// Neck Rotation
  				if(humanObject.torsoz >= -25.0f)
  					humanObject.torsoz -= 2.0f;
  			}
  			else if(mode == 4){
  				// cout<<"AAYA"<<endl;
  				if(humanObject.leftUpperArmz >= -180.0f)
  					humanObject.leftUpperArmz -= 2.0f;
  			}
  			else if(mode == 6){
  				// cout<<fabs(4.0/7.0*humanObject.rightLowerArmx)<<endl;
  				if((((int)humanObject.rightLowerArmx)%360 < 20.0f || ((int)humanObject.rightLowerArmx)%360 > 340.0f ) && humanObject.rightUpperArmy < -10.0f){
            if(humanObject.rightUpperArmz > 0.0f && humanObject.rightUpperArmz > fabs(4.0/7.0*humanObject.rightLowerArmx)){
              humanObject.rightUpperArmz -= 2.0f;
            }
          }
          else{
            if(humanObject.rightUpperArmz > 0.0f){
              humanObject.rightUpperArmz -= 2.0f;
            }
          }
  			}
  			else if(mode == 8){
  				if(humanObject.hipz > -45.0f)
  					humanObject.hipz -= 2.0f;
  			}
  			else if(mode == 9){
  				if(humanObject.leftUpperLegz > -45.0f)
  					humanObject.leftUpperLegz -= 2.0f;
  			}
  			else if(mode == 11){
  				if(humanObject.rightUpperLegz > 0.0f)
  					humanObject.rightUpperLegz -= 2.0f;
  			}
  		}
	    glutPostRedisplay();
	    break;
      }
      case 'x':{
      	if(mode >= 0){
      		if(mode == 0){
      			//Hip Translation
      			humanObject.hipTranslatex += 0.1f;
      		}
      		else if(mode == 1){
      			// Head Rotation
      			if(humanObject.headx<=45.0f)
      				humanObject.headx+=2.0f;
      		}
      		else if(mode == 2){
      			// Neck Rotation
      			if(humanObject.neckx<=25.0f)
      				humanObject.neckx+=2.0f;
      		}
      		else if(mode == 3){
      			// Neck Rotation
      			if(humanObject.torsox<=25.0f)
      				humanObject.torsox+=2.0f;
      		}
      		else if(mode == 4){
      			// Upper Arm Rotation
      			humanObject.leftUpperArmx+=2.0f;
      		}
      		else if(mode == 5){
      			if(humanObject.leftLowerArmx <= 0.0f)
      				humanObject.leftLowerArmx +=2.0f;
      		}
      		else if(mode == 6){
      			// Upper Arm Rotation
      			humanObject.rightUpperArmx+=2.0f;
      		}
      		else if(mode == 7){
      			if(humanObject.rightLowerArmx <= 0.0f)
      				humanObject.rightLowerArmx +=2.0f;
      		}
      		else if(mode == 8){
      			if(humanObject.hipx < 45.0f)
      				humanObject.hipx += 2.0f;
      		}
      		else if(mode == 9){
      			if(humanObject.leftUpperLegx < 60.0f)
      				humanObject.leftUpperLegx += 2.0f;
      		}
      		else if(mode == 10){
      			if(humanObject.leftLowerLegx < 120.0f)
      				humanObject.leftLowerLegx += 2.0f;
      		}
      		else if(mode == 11){
      			if(humanObject.rightUpperLegx < 60.0f)
      				humanObject.rightUpperLegx += 2.0f;
      		}
      		else if(mode == 12){
      			if(humanObject.rightLowerLegx < 120.0f)
      				humanObject.rightLowerLegx += 2.0f;
      		}
      	}
      	glutPostRedisplay();
	    break;
      }
      case 'X':{
      	if(mode >= 0){
      		if(mode == 0){
      			//Hip Translation
      			humanObject.hipTranslatex -= 0.1f;
      		}
      		else if(mode == 1){
      			// Head Rotation
      			if(humanObject.headx>=-45.0f)
      				humanObject.headx-=2.0f;
      		}
      		else if(mode == 2){
      			// Head Rotation
      			if(humanObject.neckx>=-25.0f)
      				humanObject.neckx-=2.0f;
      		}
      		else if(mode == 3){
      			// Head Rotation
      			if(humanObject.torsox>=-25.0f)
      				humanObject.torsox-=2.0f;
      		}
      		else if(mode == 4){
      			//Upper Arm Rotation
      			humanObject.leftUpperArmx-=2.0f;
      		}
      		else if(mode == 5){
      			if(((int)humanObject.leftUpperArmx )%360<= 10.0f && ((int)humanObject.leftUpperArmx)%360 >= -10.0f && humanObject.leftUpperArmy >= 45.0f){
      				// cout<<"First"<<":"<<humanObject.leftUpperArmx<<":"<<humanObject.leftUpperArmy<<endl;
      				if(humanObject.leftLowerArmx >= -1*(180 - ((90+humanObject.leftUpperArmz)+(180.0/M_PI)*acos(0.75*(sin(-1*humanObject.leftUpperArmz))))))
      					humanObject.leftLowerArmx -= 2.0f;
      			}
      			else{
      				// cout<<"second"<<":"<<humanObject.leftUpperArmx<<":"<<humanObject.leftUpperArmy<<endl;
      				if(humanObject.leftLowerArmx >= -135.0f )
      					humanObject.leftLowerArmx -= 2.0f;
      			}
      		}
      		else if(mode == 6){
      			//Upper Arm Rotation
      			humanObject.rightUpperArmx-=2.0f;
      		}
      		else if(mode == 7){
      			if(((int)humanObject.rightUpperArmx )%360<= 10.0f && ((int)humanObject.rightUpperArmx)%360 >= -10.0f && humanObject.rightUpperArmy <= -45.0f){
      				// cout<<"First"<<":"<<humanObject.leftUpperArmx<<":"<<humanObject.leftUpperArmy<<endl;
      				if(humanObject.rightLowerArmx >= -1*(180 - ((90-humanObject.rightUpperArmz)+(180.0/M_PI)*acos(0.75*(sin(humanObject.rightUpperArmz))))))
      					humanObject.rightLowerArmx -= 2.0f;
      			}
      			else{
      				// cout<<"second"<<":"<<humanObject.leftUpperArmx<<":"<<humanObject.leftUpperArmy<<endl;
      				if(humanObject.rightLowerArmx >= -135.0f )
      					humanObject.rightLowerArmx -= 2.0f;
      			}
      		}
      		else if(mode == 8){
      			if(humanObject.hipx > -45.0f)
      				humanObject.hipx -= 2.0f;      		
      		}
      		else if(mode == 9){
      			if(humanObject.leftUpperLegx > -90.0f)
      				humanObject.leftUpperLegx -= 2.0f;
      		}
      		else if(mode == 10){
      			if(humanObject.leftLowerLegx > 0.0f)
      				humanObject.leftLowerLegx -= 2.0f;
      		}
      		else if(mode == 11){
      			if(humanObject.rightUpperLegx > -90.0f)
      				humanObject.rightUpperLegx -= 2.0f;
      		}
      		else if(mode == 12){
      			if(humanObject.rightLowerLegx > 0.0f)
      				humanObject.rightLowerLegx -= 2.0f;
      		}
      	}
      	glutPostRedisplay();
	    break;
      }
      case 'c':{
      	if(mode >= 0){
      		if(mode == 0){
      			//Hip Translation
      			humanObject.hipTranslatey += 0.1f;
      		}
      		else if(mode == 1){
      			// Head Rotation
      			if(humanObject.heady<=60.0f)
      				humanObject.heady+=2.0f;
      		}
      		else if(mode == 2){
      			// Head Rotation
      			if(humanObject.necky<=45.0f)
      				humanObject.necky+=2.0f;
      		}
      		else if(mode == 3){
      			// Head Rotation
      			if(humanObject.torsoy<=45.0f)
      				humanObject.torsoy+=2.0f;
      		}
      		else if(mode == 4){
      			// Left Upper Arm Rotation
      			// cout<<(90+humanObject.leftUpperArmz)<<":"<<(180.0/M_PI)*acos(0.75*(sin(-1*humanObject.leftUpperArmz))) <<endl;
            if(((int)humanObject.rightUpperArmx )%360<= 20.0f || ((int)humanObject.rightUpperArmx)%360 >= 340.0f){
              // cout<<"problem case"<<endl;
              cout<<humanObject.leftUpperArmz<<":"<<humanObject.leftLowerArmx<<endl;
              if(humanObject.leftUpperArmz > 4.0/7.0*humanObject.leftLowerArmx){
                if(humanObject.leftUpperArmy < 30.0f)
                  humanObject.leftUpperArmy += 2.0f;
              }else{
                // cout<<"case 2"<<endl;
                if(humanObject.leftUpperArmy < 90.0f)
                  humanObject.leftUpperArmy += 2.0f;
              }
            }
            else{
              // cout<<"no roblem"<<endl;
              if(humanObject.leftUpperArmy < 90.0f)
                humanObject.leftUpperArmy += 2.0f;
            }
      		}
      		else if(mode == 6){
      			// Head Rotation
      			if(humanObject.rightUpperArmy<90.0f)
      				humanObject.rightUpperArmy+=2.0f;
      		}
      		else if(mode == 8){
      			if(humanObject.hipy < 30.0f)
      				humanObject.hipy += 2.0f;
      		}
      		else if(mode == 9){
      			if(humanObject.leftUpperLegy < 30.0f)
      				humanObject.leftUpperLegy += 2.0f;
      		}
      		else if(mode == 11){
      			if(humanObject.rightUpperLegy < 30.0f)
      				humanObject.rightUpperLegy += 2.0f;
      		}
      	}
      	glutPostRedisplay();
	    break;	
      }
      case 'C':{
      	if(mode >= 0){
      		if(mode == 0){
      			//Hip Translation
      			humanObject.hipTranslatey -= 0.1f;
      		}
      		else if(mode == 1){
      			// Head Rotation
      			if(humanObject.heady>=-60.0f)
      				humanObject.heady-=2.0f;
      		}
      		else if(mode == 2){
      			// Head Rotation
      			if(humanObject.necky>=-45.0f)
      				humanObject.necky-=2.0f;
      		}
      		else if(mode == 3){
      			// Head Rotation
      			if(humanObject.torsoy>=-45.0f)
      				humanObject.torsoy-=2.0f;
      		}
      		else if(mode == 4){
      			// Head Rotation
      			if(humanObject.leftUpperArmy>=-90.0f)
      				humanObject.leftUpperArmy-=2.0f;
      		}
      		else if(mode == 6){
      			// Right Upper Arm Rotation
            if(((int)humanObject.rightUpperArmx)%360 <= 20.0f || ((int)humanObject.rightUpperArmx)%360 >= 340.0f){
              // cout<<"problem"<<endl;
              if(humanObject.rightUpperArmz < fabs(4.0/7.0*humanObject.rightLowerArmx)){
                if(humanObject.rightUpperArmy > -30.0f){
                  humanObject.rightUpperArmy -= 2.0f;
                }
              }
              else  if(humanObject.rightUpperArmy > -90.0f){
                      humanObject.rightUpperArmy -= 2.0f;
                    }
              else{
                // cout<<"no problem"<<endl;
                if(humanObject.rightUpperArmy > -90.0f){
                  humanObject.rightUpperArmy -= 2.0f;
                }
              }
            }
      		}
      		else if(mode == 8){
      			if(humanObject.hipy > -30.0f)
      				humanObject.hipy -= 2.0f;
      		}
      		else if(mode == 9){
      			if(humanObject.leftUpperLegy > -30.0f)
      				humanObject.leftUpperLegy -= 2.0f;
      		}
      		else if(mode == 11){
      			if(humanObject.rightUpperLegy > -30.0f)
      				humanObject.rightUpperLegy -= 2.0f;
      		}
      	}
      	glutPostRedisplay();
	    break;	
      }
		/*	float headx;
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
*/      
      default:
      {

      }   
   }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutKeyboardFunc( keyboard );
   glutSpecialFunc(inputKey);
   glutMouseFunc( mouse );
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}