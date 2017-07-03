#pragma once

#include <vector>
#include "dank_glyph.h"
#include "Math/dank_vec4.h"

struct dank_label {
	dank_label();
	~dank_label();

	std::vector<dank_glyph> glyphs;
	dank_vec4 color;
};