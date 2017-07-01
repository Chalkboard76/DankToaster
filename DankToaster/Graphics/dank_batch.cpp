#include "dank_batch.h"

dank_batch::dank_batch() {
	num_sheets = 0;
}
dank_batch::~dank_batch() {
}

int dank_batch::submit(dank_renderable renderable) {
	unsigned int texID = renderable.tex_ID;
	if (map.find(texID) == map.end()) {
		if (num_sheets >= 32) {
			return 0;
		}
		map.insert(std::unordered_map<unsigned int, float>::value_type(texID, num_sheets));
		num_sheets++;
	}
	renderables.push_back(renderable);
	return 1;
}

void dank_batch::clear() {
	map.clear();
	renderables.clear();
	num_sheets = 0;
}
