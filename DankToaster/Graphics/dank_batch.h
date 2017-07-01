#pragma once

#include "dank_renderable.h"
#include <vector>
#include <unordered_map>

struct dank_batch {
	const static short sheet_capacity = 32;
	float num_sheets;
	std::unordered_map<unsigned int, float> map;
	std::vector<dank_renderable> renderables;
	
	dank_batch();
	~dank_batch();

	int submit(dank_renderable renderable);
	void clear();
};