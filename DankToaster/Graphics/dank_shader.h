#pragma once

#include <GL\glew.h>
#include "Math\dank_mat4.h"


class dank_shader {
private:
	GLuint _programID;
public:
	dank_shader();
	dank_shader(const char* vert, const char* frag);
	~dank_shader();
	void init(const char* vert, const char* frag);
	void enable();
	void disable();
	inline GLuint getProgramID() { return _programID; }
	void setUniformMat4(char* name, dank_mat4 matrix);
	void setUniform1fv(char* name, float* data, int count);
	void setUniform1v(char* name, int* data, int count);
	void setUniform1i(char* nam, int data);
};
