#include "dank_window.h"

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void resize_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

dank_window::dank_window(const int width, const int height, const char* title) {
	glfwSetErrorCallback(error_callback);

	_width = width;
	_height = height;
	_title = title;

	if (!glfwInit()) {
		printf("%s\n", "GLFW failed to initialize.");
		glfwTerminate();
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if (!_window)
	{
		printf("%s\n", "GLFW failed to create a the dank_window.");
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);
	glfwSetWindowSizeCallback(_window, resize_callback);

	if (glewInit() != GLEW_OK) {
		printf("%s\n", "Failed to initialize GLEW.");
		glfwTerminate();
	}
}
dank_window::~dank_window() {
	glfwDestroyWindow(_window);
	glfwTerminate();
}

void dank_window::update() {
	glfwSwapBuffers(_window);
	glfwPollEvents();
}
