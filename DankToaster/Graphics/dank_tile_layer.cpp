#include "dank_tile_layer.h"

dank_tile_layer::dank_tile_layer() {
}

dank_tile_layer::dank_tile_layer(float width, float height, float depth, int max_sprites) {
	_batch_renderer = new dank_batch_renderer(width, height);
	_square_renderer = new dank_colored_square_renderer(width, height);
	_text_renderer = new dank_text_renderer(width, height);
	_depth = depth;
	_sprite_count = 0;
}

dank_tile_layer::~dank_tile_layer() {
	delete _batch_renderer;
	delete _text_renderer;
	delete _square_renderer;
}

void dank_tile_layer::add(dank_sprite* sprite) {
	_sprites.push_back(sprite);
	_sprite_count++;
}

void dank_tile_layer::render() {
	_batch_renderer->submit(_sprites);
	_batch_renderer->render();
}

int dank_tile_layer::getSpriteCount() {
	return _sprite_count;
}