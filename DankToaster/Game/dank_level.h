#pragma once

#include <vector>
#include "dank_tile.h"

class dank_level {
private:
	float left, right, top, bottom, b_width, b_height;
public:
	std::vector<dank_tile*> tiles;

	dank_level(const char* map_filepath, dank_texture_sheet sheet);
	~dank_level();
};