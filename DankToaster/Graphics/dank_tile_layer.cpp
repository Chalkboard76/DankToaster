#include "dank_tile_layer.h"

dank_tile_layer::dank_tile_layer() {
}

dank_tile_layer::dank_tile_layer(dank_batch_renderer* renderer, dank_shader* shader, float depth, int max_sprites) {
	_renderer = renderer;
	_shader = shader;
	_depth = depth;
	_sprites = new dank_sprite[max_sprites];
	_sprite_count = 0;
}

dank_tile_layer::~dank_tile_layer() {
	delete[] _sprites;
}

void dank_tile_layer::add(dank_sprite* sprite) {
	_sprites[_sprite_count] = *sprite;
	_sprite_count++;
}

void dank_tile_layer::render() {
	_shader->enable();
	_renderer->submit(_sprites, _sprite_count);
	_renderer->render();
}

int dank_tile_layer::getSpriteCount() {
	return _sprite_count;
}