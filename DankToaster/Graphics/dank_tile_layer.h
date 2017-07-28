#pragma once

#include "dank_batch_renderer.h"
#include "dank_sprite.h"
#include <vector>

class dank_tile_layer {
private:
	dank_batch_renderer* _renderer;
	float _depth;
	dank_sprite* _sprites;
	int _sprite_count;

public:
	dank_tile_layer();
	dank_tile_layer(dank_batch_renderer* renderer, float depth, int max_sprites);
	~dank_tile_layer();

	void add(dank_sprite* sprite);
	void render();
	int getSpriteCount();

};