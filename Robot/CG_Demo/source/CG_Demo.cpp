/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 */

 // Please don't change lines 9-31 (It helps me to grade)
#ifdef APPLE
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef unix
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "cRobot.h"

Robot* robot;

void init() // FOR GLUT LOOP
{
	robot = new Robot();

	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	//gluLookAt(5.0, 6.0, 10.0,										// Where the camera is.
	gluLookAt(0.0, 0.0, 8.0,
				0.0, 0.0, 0.0,										// To where the camera points at.
				0.0, 1.0, 0.0);										// "UP" vector.

	robot->draw();

	glutSwapBuffers();
	// Swap the hidden and visible buffers.
}

void idle()                                                            // Called when drawing is finished.
{
	robot->update();
	glutPostRedisplay();                                            // Display again.
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
	glLoadIdentity();                                                // Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
	glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
	gluLookAt(0.0, 1.0, 30.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	display();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG first program");

	init();
	glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
	glutDisplayFunc(display);                                        // Display CALLBACK function.
	glutIdleFunc(idle);                                                // Idle CALLBACK function.
	glutMainLoop();                                                    // Begin graphics program.
	return 0;                                                        // ANSI C requires a return value.
}