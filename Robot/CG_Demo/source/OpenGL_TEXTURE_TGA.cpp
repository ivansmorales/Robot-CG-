/*
	Computer Graphics. TC3022.

	Basic TGA textures.
	Displays a textured cube with vertices, normals and texture coordinates.
*/

#pragma once
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#include "cCube.h"
#include "cRobot.h"

Cube*		cube0;
Cube*		cube1;
Robot*		robot;

GLfloat		rotation;
GLfloat*	mat0_specular;
GLfloat*	mat0_diffuse;
GLfloat*	mat0_shininess;
GLfloat*	light0_position;
//
//----------------------------------------------------------------------------------------------
//
void init( void )
{
	cube0				= new Cube( 1.0f, false );
	cube1				= new Cube( 1.0f, true	);
	robot = new Robot();
	glEnable( GL_TEXTURE_2D );
	glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
	glShadeModel ( GL_SMOOTH );

	mat0_specular		= new GLfloat[4];
	mat0_specular[0]	= 1.0f; //<----------------------------------S0r
	mat0_specular[1]	= 1.0f; //<----------------------------------S0g
	mat0_specular[2]	= 1.0f; //<----------------------------------S0b
	mat0_specular[3]	= 1.0f; //<----------------------------------S0a

	mat0_diffuse		= new GLfloat[4];
	mat0_diffuse[0]		= 1.0f; //<----------------------------------D0r
	mat0_diffuse[1]		= 0.0f; //<----------------------------------D0g
	mat0_diffuse[2]		= 0.0f; //<----------------------------------D0b
	mat0_diffuse[3]		= 1.0f; //<----------------------------------D0a

	mat0_shininess		= new GLfloat[1];
	mat0_shininess[0]	= 60.0f;

	light0_position		= new GLfloat[4];
	light0_position[0]	= 1.0f; //<----------------------------------L0x
	light0_position[1]	= 1.0f; //<----------------------------------L0y
	light0_position[2]	= 1.0f; //<----------------------------------L0z
	light0_position[3]	= 0.0f; //<----------------------------------L0w

	glLightfv( GL_LIGHT0, GL_POSITION,  light0_position );
	//glEnable( GL_LIGHTING );
	//glEnable( GL_LIGHT0 );
	glEnable( GL_DEPTH_TEST );
	rotation = 0.0f;
}
//
//----------------------------------------------------------------------------------------------
//
void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	//gluLookAt(0.0, 0.0, 6.0,										// Where the camera is.
	//	0.0, 0.0, 0.0,										// To where the camera points at.
	//	0.0, 1.0, 0.0);										// "UP" vector.

	//glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//glMaterialfv( GL_FRONT,	 GL_DIFFUSE,   mat0_diffuse		);
	//glMaterialfv( GL_FRONT,  GL_SPECULAR,  mat0_specular	);
	//glMaterialfv( GL_FRONT,  GL_SHININESS, mat0_shininess	);
	//glPushMatrix();
	////glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	robot->draw();
	glScalef(10.0f, 10.0f, 10.0f);
	glTranslatef(0.0f, 0.0f, -1.0f );
	cube0->draw();
	//glPopMatrix();
	//glPopMatrix();
	////glPushMatrix();

	//glPopMatrix();

	glutSwapBuffers();
}
//
//----------------------------------------------------------------------------------------------
//
void idle( void )
{
	rotation += 0.02f;
	if( rotation > 360.0f )
	{
		rotation = 0.0f;
	}
	glutPostRedisplay();
}
//
//----------------------------------------------------------------------------------------------
//
void reshape( int w, int h )
{
	glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	if( w <= h )
	{
		glOrtho(- 1.5, 
				  1.5, 
				- 1.5 * (GLfloat)h / (GLfloat)w,
				  1.5 * (GLfloat)h / (GLfloat)w,
				-10.0,
				 10.0							);
	}
	else
	{
	    glOrtho(- 1.5 * (GLfloat)w / (GLfloat)h,
				  1.5 * (GLfloat)w / (GLfloat)h,
			    - 1.5,
				  1.5,
			    -10.0,
			     10.0							);
	}
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}
//
//----------------------------------------------------------------------------------------------
//
int main( int argc, char** argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowSize( 800, 800 );
	glutInitWindowPosition( 100, 100 );
	glutCreateWindow( argv[0] );
	init();
	glutDisplayFunc( display ); 
	glutReshapeFunc( reshape );
	glutIdleFunc( idle );
	glutMainLoop();
	return 0;
}
//
//----------------------------------------------------------------------------------------------