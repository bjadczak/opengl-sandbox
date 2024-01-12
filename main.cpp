#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Init GLFW
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Init GLFW

	// Create window and set as current context
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGLSandbox", NULL, NULL);
	if (window == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Create window and set as current context

	// Init GLAD
	gladLoadGL();

	// Set viewport of OpenGL in the Window
	glViewport(0, 0, 800, 800);

	// Set color of background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap buffers
	glfwSwapBuffers(window);

	// Window loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	// Termination
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}