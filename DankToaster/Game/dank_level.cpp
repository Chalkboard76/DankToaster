#include "dank_level.h"
#include <fstream>

dank_level::dank_level(const char* map_filepath, dank_texture_sheet& sheet) {
	float pos = 0.0;
	std::ifstream map(map_filepath);
	std::string string;
	std::getline(map, string);
	left = std::strtof(string.c_str(), 0);
	std::getline(map, string);
	right = std::strtof(string.c_str(), 0);
	std::getline(map, string);
	top = std::strtof(string.c_str(), 0);
	std::getline(map, string);
	bottom = std::strtof(string.c_str(), 0);
	std::getline(map, string);
	b_width = std::strtof(string.c_str(), 0);
	std::getline(map, string);
	b_height = std::strtof(string.c_str(), 0);

	float blah = (right - left) / b_width;
	float bloo = (bottom - top) / b_height;
	for (float j = top; j < bottom; j += bloo) {
		for (float i = left; i < right; i += blah, map.get()) {
			string = map.get();
			int temp = std::stoi(string);
			tiles.push_back(new dank_tile(i, j, blah, bloo, *sheet.textures[temp]));
		}
	}
}

dank_level::~dank_level() {
	for (int i = 0; i < tiles.size(); i++) {
		delete tiles[i];
	}
}

