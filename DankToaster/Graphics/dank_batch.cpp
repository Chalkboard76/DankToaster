#include "dank_batch.h"

dank_batch::dank_batch() {
	num_sheets = 0;
	for (int i = 0; i < max_map_size; i++) {
		map[i] = -1.0f;
	}
}
dank_batch::~dank_batch() {
}

int dank_batch::submit(dank_renderable renderable) {
	unsigned int tex_ID = renderable.tex_ID;
	if (map[tex_ID] == -1.0f) {
		if (num_sheets >= 32) {
			return 0;
		}
		indices.push_back(tex_ID);
		map[tex_ID] = num_sheets;
		num_sheets++;
	}
	renderables.push_back(renderable);
	return 1;
}

void dank_batch::clear() {
	indices.clear();
	renderables.clear();
	num_sheets = 0;
}
bool dank_batch::empty() {
	return num_sheets <= 0;
}
