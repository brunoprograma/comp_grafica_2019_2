/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

float angulo = 0.0f;

typedef struct {
	float x;
	float y;
	float angulo;
} quadrado_t;

quadrado_t vet[10];

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

void quadrado(quadrado_t q) {
	glLoadIdentity();
	angulo = angulo + 0.02f;
	glColor3f(q.x, q.y, q.angulo * 0.1f);
	glTranslatef(q.x, q.y, 0.0f);
	glRotatef(q.angulo+angulo, 1.0f, 1.0f, 0.0f);
	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);
}

void display()
{
	int i;

	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	for (i=0; i < 10; i++) {
		quadrado(vet[i]);	
	}

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	int i;
	for (i=0; i < 10; i++) {
		vet[i].x = (float) i / 10.0f;
		vet[i].y = (float) i / 10.0f;
		vet[i].angulo = i * 15.0f;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
