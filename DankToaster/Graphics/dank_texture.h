#pragma once

#include <string>
#include "Math/dank_vec2.h"

struct dank_texture {
	unsigned int tex_ID;
	dank_vec2 UV;
	float width, height;
	dank_texture();
	dank_texture(dank_vec2 coord, float width, float height);
	~dank_texture();
};
