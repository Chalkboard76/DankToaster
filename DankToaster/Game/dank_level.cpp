#include "dank_level.h"
#include <iostream>
#include <ios>
#include <fstream>
#include "Graphics\dank_texture_sheet.h"

dank_level::dank_level(const char* map_filepath, dank_texture_sheet sheet) {
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
	float bloo = (top - bottom) / b_height;
	for (float i = left; i < right; i += blah) {
		for (float j = top; j < bottom; j += bloo) {
			string = map.get();
			tiles.push_back(new dank_tile(i, j, blah, bloo, *sheet.textures[std::stoi(string)]));
		}
	}
}

dank_level::~dank_level() {
	for (int i = 0; i < tiles.size(); i++) {
		delete tiles[i];
	}
}

