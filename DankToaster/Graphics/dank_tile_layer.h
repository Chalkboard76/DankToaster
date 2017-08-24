#pragma once

#include "Renderers\dank_batch_renderer.h"
#include "Renderers\dank_colored_square_renderer.h"
#include "Renderers\dank_text_renderer.h"
#include "dank_sprite.h"
#include <vector>

class dank_tile_layer {
private:
	dank_batch_renderer* _batch_renderer;
	dank_text_renderer* _text_renderer;
	dank_colored_square_renderer* _square_renderer;

	float _depth;
	std::vector<dank_sprite*> _sprites;
	int _sprite_count;


public:
	dank_tile_layer();
	dank_tile_layer(float width, float height, float depth, int max_sprites);
	~dank_tile_layer();

	void add(dank_sprite* sprite);
	void render();
	int getSpriteCount();

};