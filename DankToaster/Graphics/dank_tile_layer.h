#pragma once

#include "Renderers\dank_batch_renderer.h"
#include "Renderers\dank_colored_square_renderer.h"
#include "Renderers\dank_text_renderer.h"
#include "dank_sprite.h"
#include "Game\dank_level.h"
#include <vector>

class dank_tile_layer {
private:
	dank_batch_renderer* _batch_renderer;
	dank_text_renderer* _text_renderer;
	dank_colored_square_renderer* _square_renderer;

	float _depth;
	std::vector<dank_sprite*> _sprites;
	int _sprite_count;
	dank_mat4 view;


public:
	dank_tile_layer();
	dank_tile_layer(float width, float height, float depth, int max_sprites);
	~dank_tile_layer();

	void add(dank_sprite* sprite);
	void render();
	int getSpriteCount();
	void set_level(dank_level* level);
	void scroll_up(float amount);
	void scroll_down(float amount);
	void scroll_left(float amount);
	void scroll_right(float amount);
	void translate_layer();

};