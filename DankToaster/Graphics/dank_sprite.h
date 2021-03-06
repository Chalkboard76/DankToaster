#pragma once

#include "Math/dank_vec3.h"
#include "Math/dank_vec4.h"
#include "dank_vertex_textured.h"
#include "dank_renderable.h"

struct dank_sprite : dank_renderable {
	dank_sprite();
	dank_sprite(float xcoord, float ycoord, float width, float height, dank_texture& texture);
	~dank_sprite();
};
