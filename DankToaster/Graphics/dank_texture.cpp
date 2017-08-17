#include "dank_texture.h"

dank_texture::dank_texture() {
}
dank_texture::dank_texture(dank_vec2 coord, float width, float height) {
	UV = coord;
	this->width = width;
	this->height = height;
}
dank_texture::~dank_texture() {

}
