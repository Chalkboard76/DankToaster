#pragma once
#include <GL\glew.h>
#include "Math\dank_vec2.h"
struct dank_character {
	GLuint		tex_ID;
	dank_vec2	size;
	dank_vec2	bearing;
	GLuint		advance;
};