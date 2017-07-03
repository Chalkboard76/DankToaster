#pragma once

#include <string>
#include "dank_texture_sheet.h"
#include "Math/dank_vec2.h"

struct dank_texture {
	unsigned int tex_ID;
	dank_vec2 UV;
	float width, height;
	dank_texture();
	dank_texture(const dank_texture_sheet& sheet, dank_vec2 coord, float width, float height);
	~dank_texture();
};
