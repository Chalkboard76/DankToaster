#pragma once

#include <string>
#include <vector>
#include "dank_texture.h"

struct dank_texture_sheet {
	unsigned int tex_ID;
	std::vector<dank_texture*> textures;

	dank_texture_sheet();
	dank_texture_sheet(const std::string& path, float width, float height, float tex_size);
	~dank_texture_sheet();
};
