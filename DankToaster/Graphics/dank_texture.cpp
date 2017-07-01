#include "dank_texture.h"

dank_texture::dank_texture() {
}
dank_texture::dank_texture(const dank_texture_sheet& sheet, dank_vec2 coord, float width, float height) {
	texID = sheet.tex_ID;
	UV = coord;
	this->width = width;
	this->height = height;
}
dank_texture::~dank_texture() {

}
