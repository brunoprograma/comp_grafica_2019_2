/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

int rot = 1, sca = 1, tra = 1;
float i = 0.0f, g = 0.0f, s = 2.0f, dir = -1.0f;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a red square
	glColor3f(1, 0, 0);
	if (tra == 1) {
		if (i <= -1.0f) {
			dir = 1.0f;
		} else if (i >= 1.0f) {
			dir = -1.0f;
		}
		i = i + 0.01f*dir;
		glTranslatef(i, 0, 0);
	}	
	if (rot == 1) {
		if (g == 360.0f)
			g = 0.0f;
		else
			g = g + 2.f;
		glRotatef(g*-dir, 0.0f, 0.0f, 1.0f);
	}
	if (sca == 1) {
		s = s + (0.01f*-dir);
		glScalef(s, s, 0.0f);
	}
	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	//glLoadIdentity();

	// Render a blue square
	//glColor3f(0, 0, 1);
	//glTranslatef(0.2f, 0.2f, 0);
	//glRotatef(45.0f, 0, 0, 1.0f);
	//glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	} else if (key == 49) { // 1
		rot = (rot == 1) ? 0 : 1;
	} else if (key == 50) { // 2
		tra = (tra == 1) ? 0 : 1;
	} else if (key == 51) { // 3
		sca = (sca == 1) ? 0 : 1;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
