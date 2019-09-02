/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500

float x1 = -0.99f;
float y1 = 0.40f;
float sentido = 1.0f;

int main() {
	GLFWwindow* window;
	int width, height;

	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glBegin(GL_LINES);
			if (x1 >= 0.39f) {
				sentido = -1.f;
			} else if (x1 <= -0.99f) {
				sentido = 1.f;
			}
			x1 += 0.02f * sentido;
			glColor3f(1.f, 0.f, 0.f);
			
			// esquerda
			glVertex3f(x1, y1, 0.f);
			glVertex3f(x1, y1-0.4, 0.f);

			// diagonal cima esq
			glVertex3f(x1, y1, 0.f);
			glVertex3f(x1+0.2, y1+0.2, 0.f);

			// dir
			glVertex3f(x1+0.4, y1, 0.f);
			glVertex3f(x1+0.4, y1-0.4, 0.f);

			// diagonal cima dir
			glVertex3f(x1+0.4, y1, 0.f);
			glVertex3f(x1+0.6, y1+0.2, 0.f);

			// linha mais de cima
			glVertex3f(x1+0.2, y1+0.2, 0.f);
			glVertex3f(x1+0.6, y1+0.2, 0.f);

			// linha de cima
			glVertex3f(x1, y1, 0.f);
			glVertex3f(x1+0.4, y1, 0.f);
			
			// linha de baixo
			glVertex3f(x1, y1-0.4, 0.f);
			glVertex3f(x1+0.4, y1-0.4, 0.f);

			// diag de baixo
			glVertex3f(x1+0.4, y1-0.4, 0.f);
			glVertex3f(x1+0.6, y1-0.2, 0.f);

			// diagonal fora dir
			glVertex3f(x1+0.6, y1+0.2, 0.f);
			glVertex3f(x1+0.6, y1-0.2, 0.f);
	
			glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
