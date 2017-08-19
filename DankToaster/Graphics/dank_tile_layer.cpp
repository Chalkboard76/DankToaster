#include "dank_tile_layer.h"

dank_tile_layer::dank_tile_layer() {
}

dank_tile_layer::dank_tile_layer(dank_batch_renderer* renderer, float depth, int max_sprites) {
	_renderer = renderer;
	_depth = depth;
	_sprite_count = 0;
}

dank_tile_layer::~dank_tile_layer() {
}

void dank_tile_layer::add(dank_sprite* sprite) {
	_sprites.push_back(sprite);
	_sprite_count++;
}

void dank_tile_layer::render() {
	_renderer->submit(_sprites);
	_renderer->render();
}

int dank_tile_layer::getSpriteCount() {
	return _sprite_count;
}