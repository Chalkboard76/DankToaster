#pragma once

#include "Math\dank_vec2.h"
#include "Math\dank_vec3.h"
#include "dank_texture.h"

struct dank_vertex {
	dank_vec3	position;
	dank_vec2	UV;
	float		tex_unit;
};
