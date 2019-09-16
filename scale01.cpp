/**
 * A simple OpenGL program that draws a colorful cube
 * that rotates as you move the arrow keys.
 *
 * Author: Mihalis Tsoukalos
 * Date: Wednesday 04 June 2014
 */

#include <GL/glut.h>
#include <GL/gl.h>

// Scale X
GLfloat sX = 0.0f;
// Scale Y
GLfloat sY = 0.0f;

// The coordinates for the vertices of the cube
GLfloat x = 0.1f;
GLfloat y = 0.1f;
GLfloat z = 0.0f;

void display()
{
	// Set Background Color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Scale with pressed number
	glScalef(sX, sY, 0.0f);

	// BACK
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
		
		glVertex3f(-x, y, z);
		glVertex3f(-x, -y, z);
		
		glVertex3f(x, y, z);
		glVertex3f(-x, y, z);

		glVertex3f(x, -y, z);
		glVertex3f(-x, -y, z);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	
	sX += (float) key - 48;
	sY += (float) key - 48;

	// Request display update
	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);

	// Create window
	glutCreateWindow("OpenGL Cube");

	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	// Pass control to GLUT for events
	glutMainLoop();

	return 0;
}
