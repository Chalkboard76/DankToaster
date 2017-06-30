#pragma once

#include <string>

struct dank_texture_sheet {
	unsigned int texID;

	dank_texture_sheet(const std::string& path);
	~dank_texture_sheet();
};
