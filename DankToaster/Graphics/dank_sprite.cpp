#include "dank_sprite.h"

dank_sprite::dank_sprite(float xcoord, float ycoord, float width, float height, dank_vec4 color) {
	vertices[1] = { dank_vec3(xcoord, ycoord, 1), color };
	vertices[2] = { dank_vec3(xcoord + width, ycoord, 1), color };
	vertices[3] = { dank_vec3(xcoord + width, ycoord + height, 1), color };
	vertices[4] = { dank_vec3(xcoord, ycoord + height, 1), color };
}
dank_sprite::~dank_sprite() {
}