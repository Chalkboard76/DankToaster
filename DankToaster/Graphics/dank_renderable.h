#pragma once
#include "dank_vertex_textured.h"

struct dank_renderable {
	unsigned int tex_ID;
	dank_vertex_textured vertices[4];
};