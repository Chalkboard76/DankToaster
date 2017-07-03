#pragma once
#include "dank_renderable.h"
#include <GL\glew.h>
#include "dank_character.h"

struct dank_glyph : dank_renderable {
	dank_glyph();
	dank_glyph(int x, int y, int z, int scale, dank_character c, dank_character H);
	~dank_glyph();
};