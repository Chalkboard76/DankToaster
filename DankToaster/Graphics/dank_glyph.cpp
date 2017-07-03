#include "dank_glyph.h"

dank_glyph::dank_glyph() {

}
dank_glyph::~dank_glyph(){
}

dank_glyph::dank_glyph(int x, int y, int z, int scale, dank_character c, dank_character H) {
	tex_ID = c.tex_ID;
	GLfloat xpos = x + c.bearing.x * scale;
	GLfloat ypos = y + (H.bearing.y - c.bearing.y) * scale;
	GLfloat w = c.size.x * scale;
	GLfloat h = c.size.y * scale;
	vertices[0].position = dank_vec3(x, y, z);
	vertices[0].UV = dank_vec2(0.0f, 0.0f);
	vertices[1].position = dank_vec3(x + w, y, z);
	vertices[1].UV = dank_vec2(1.0f, 0.0f);
	vertices[2].position = dank_vec3(x + w, y + h, z);
	vertices[2].UV = dank_vec2(1.0f, 1.0f);
	vertices[3].position = dank_vec3(x, y + h, z);
	vertices[3].UV = dank_vec2(0.0f, 1.0f);

}