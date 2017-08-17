#include "dank_tile.h"

dank_tile::dank_tile(float xcoord, float ycoord, float width, float height, dank_texture& texture) {
	tex_ID = texture.tex_ID;

	vertices[0].position = dank_vec3(xcoord, ycoord, 0);
	vertices[0].UV = dank_vec2(texture.UV.x, texture.UV.y);

	vertices[1].position = dank_vec3(xcoord + width, ycoord, 0);
	vertices[1].UV = dank_vec2(texture.UV.x + texture.width, texture.UV.y);

	vertices[2].position = dank_vec3(xcoord + width, ycoord + height, 0);
	vertices[2].UV = dank_vec2(texture.UV.x + texture.width, texture.UV.y + texture.height);

	vertices[3].position = dank_vec3(xcoord, ycoord + height, 0);
	vertices[3].UV = dank_vec2(texture.UV.x, texture.UV.y + texture.height);

}

dank_tile::~dank_tile() {

}