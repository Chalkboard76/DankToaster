#pragma once

#include "Graphics\dank_sprite.h"

class dank_tile : dank_sprite {
private:
public:
	dank_tile(float xcoord, float ycoord, float width, float height, dank_texture& texture);
	~dank_tile();
	
	bool solid = false;
	bool dynamic = false;
};