#pragma once

#include "dank_vertex_colored.h"

struct dank_colored_square {
	dank_vertex_colored vertices[4];

	dank_colored_square();
	dank_colored_square(float xcoord, float ycoord, float width, float height, dank_vec4 color);
	~dank_colored_square();
};