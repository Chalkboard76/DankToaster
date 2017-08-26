#include "dank_tile_layer.h"

dank_tile_layer::dank_tile_layer() {
}

dank_tile_layer::dank_tile_layer(float width, float height, float depth, int max_sprites) {
	_batch_renderer = new dank_batch_renderer(width, height);
	_square_renderer = new dank_colored_square_renderer(width, height);
	_text_renderer = new dank_text_renderer(width, height);
	_depth = depth;
	_sprite_count = 0;
	view = translationMatrix(dank_vec3(0, 0, 0));
	_batch_renderer->shader->enable();
	_batch_renderer->shader->setUniformMat4("view", view);
	_square_renderer->shader->enable();
	_square_renderer->shader->setUniformMat4("view", view);
	_text_renderer->shader->enable();
	_text_renderer->shader->setUniformMat4("view", view);
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

/* Adds all the tiles of the level to the tile layer.
STILL NEED TO FIGURE OUT A WAY TO REMOVE A PREVIOUS LEVEL. */
void dank_tile_layer::set_level(dank_level* level) {
	for (int i = 0; i < level->tiles.size(); i++) {
		add(level->tiles[i]);
	}
}

void dank_tile_layer::scroll_up(float amount) {
	view.elements[13] += amount;
	translate_layer();
}

void dank_tile_layer::scroll_down(float amount) {
	view.elements[13] -= amount;
	translate_layer();
}

void dank_tile_layer::scroll_left(float amount) {
	view.elements[12] += amount;
	translate_layer();
}

void dank_tile_layer::scroll_right(float amount) {
	view.elements[12] -= amount;
	translate_layer();
}

void dank_tile_layer::translate_layer() {
	_batch_renderer->shader->enable();
	_batch_renderer->shader->setUniformMat4("view", view);
	_square_renderer->shader->enable();
	_square_renderer->shader->setUniformMat4("view", view);
	_text_renderer->shader->enable();
	_text_renderer->shader->setUniformMat4("view", view);
}