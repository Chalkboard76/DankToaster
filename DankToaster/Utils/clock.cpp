#include "clock.h"
#include <GLFW\glfw3.h>
#include <stdio.h>

dank_clock::dank_clock() {
	_lastTime = glfwGetTime();
	_frames = 0;
}
dank_clock::~dank_clock() {
}
void dank_clock::tick() {
	_currentTime = glfwGetTime();
	_frames++;
	if (_currentTime - _lastTime >= 1.0) {
		printf("%f frames/s\n", double(_frames));
		_frames = 0;
		_lastTime += 1.0;
	}
}
