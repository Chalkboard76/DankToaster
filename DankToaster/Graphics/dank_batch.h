#pragma once

#include "dank_renderable.h"
#include <vector>
#include <unordered_map>

struct dank_batch {
	const static short max_map_size = 500;
	const static short sheet_capacity = 32;
	float	num_sheets;
	float	map[max_map_size];
	std::vector<int> indices;
	std::vector<dank_renderable> renderables;
	
	dank_batch();
	~dank_batch();

	int submit(dank_renderable renderable);
	void clear();
	bool empty();
};