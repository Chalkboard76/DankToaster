#pragma once

#include <string>

struct dank_texture_sheet {
	unsigned int tex_ID;

	dank_texture_sheet();
	dank_texture_sheet(const std::string& path);
	~dank_texture_sheet();
};
