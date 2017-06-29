#include "Clock.h"
#include <GLFW\glfw3.h>
#include <stdio.h>

Clock::Clock() {
	_lastTime = glfwGetTime();
	_frames = 0;
}
Clock::~Clock() {
}
double Clock::tick() {
	_currentTime = glfwGetTime();
	_frames++;
	double result;
	if (_currentTime - _lastTime >= 1.0) {
		result = double(_frames);
		_frames = 0;
		_lastTime += 1.0;
	}
	return result;
}
