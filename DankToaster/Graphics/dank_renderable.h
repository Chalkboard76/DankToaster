#pragma once
#include "dank_vertex.h"

struct dank_renderable {
	unsigned int tex_ID;
	dank_vertex vertices[4];
};