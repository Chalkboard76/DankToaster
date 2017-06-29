#include "Clock.h"
#include <GLFW\glfw3.h>
#include <stdio.h>

clock::clock() {
	_lastTime = glfwGetTime();
	_frames = 0;
}
clock::~clock() {
}
void clock::tick() {
	_currentTime = glfwGetTime();
	_frames++;
	if (_currentTime - _lastTime >= 1.0) {
		printf("%f frames/s\n", double(_frames));
		_frames = 0;
		_lastTime += 1.0;
	}
}
