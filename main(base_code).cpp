//Craig testing git, last name branch

#pragma comment(lib, "GLFW")
#pragma comment(lib, "OpenGL32")

#include <GL\glfw.h>
#include <cstdlib>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

bool running = true;

void initialise()
{
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

void update(double deltaTime)
{
	running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers();
}

int main()
{
	if (!glfwInit())
		exit(EXIT_FAILURE);

	if (!glfwOpenWindow(800, 600, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	initialise();

	double prevTimeStamp = glfwGetTime();
	double currentTimeStamp;
	while (running)
	{
		currentTimeStamp = glfwGetTime();
		update(currentTimeStamp - prevTimeStamp);
		render();
		prevTimeStamp = currentTimeStamp;
	}

	glfwTerminate();

	exit(EXIT_SUCCESS);
}

