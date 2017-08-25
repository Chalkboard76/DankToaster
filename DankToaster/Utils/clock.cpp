#include "clock.h"
#include <GLFW\glfw3.h>
#include <stdio.h>

dank_clock::dank_clock() {
	_lastTime = glfwGetTime();
}
dank_clock::~dank_clock() {
}

void dank_clock::init() {
	_lastTime = glfwGetTime();
}
double dank_clock::tick() {
	_currentTime = glfwGetTime();
	double result = _currentTime - _lastTime;
	_lastTime = _currentTime;
	return result;
}
