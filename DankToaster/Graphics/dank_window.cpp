#include "dank_window.h"

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void resize_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

void character_callback(GLFWwindow* window, unsigned int codepoint)
{
	std::cout << codepoint << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	dank_window* win = (dank_window*) glfwGetWindowUserPointer(window);
	win->keys[key] = action != GLFW_RELEASE;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	dank_window* win = (dank_window*) glfwGetWindowUserPointer(window);
	float xoffset = win->cursor_x - xpos;
	float yoffset = ypos - win->cursor_y;

	win->_camera->process_mouse_movement(xoffset, yoffset);

	win->cursor_x = xpos;
	win->cursor_y = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	dank_window* win = (dank_window*)glfwGetWindowUserPointer(window);
	win->mouse[button] = action != GLFW_RELEASE;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}
dank_window::dank_window(const int width, const int height, const char* title) {
	glfwSetErrorCallback(error_callback);

	_width = width;
	_height = height;
	_title = title;

	for (int i = 0; i < MAX_KEYS; i++) {
		keys[i] = false;
	}

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
	glfwSetWindowUserPointer(_window, this);
	glfwSetWindowSizeCallback(_window, resize_callback);
	glfwSetCharCallback(_window, character_callback);
	glfwSetKeyCallback(_window, key_callback);
	glfwSetCursorPosCallback(_window, cursor_position_callback);
	glfwSetMouseButtonCallback(_window, mouse_button_callback);

	if (glewInit() != GLEW_OK) {
		printf("%s\n", "Failed to initialize GLEW.");
		glfwTerminate();
	}
}

dank_window::dank_window(const int width, const int height, const char* title, dank_camera* camera) {
	glfwSetErrorCallback(error_callback);

	_width = width;
	_height = height;
	_title = title;
	_camera = camera;

	for (int i = 0; i < MAX_KEYS; i++) {
		keys[i] = false;
	}

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
	glfwSetWindowUserPointer(_window, this);
	glfwSetWindowSizeCallback(_window, resize_callback);
	glfwSetCharCallback(_window, character_callback);
	glfwSetKeyCallback(_window, key_callback);
	glfwSetCursorPosCallback(_window, cursor_position_callback);
	glfwSetMouseButtonCallback(_window, mouse_button_callback);

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
