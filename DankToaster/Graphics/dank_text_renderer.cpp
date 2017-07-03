#include "dank_text_renderer.h"
#include <ft2build.h>
#include FT_FREETYPE_H

dank_text_renderer::dank_text_renderer(int width, int height) {
	shader.init("Shaders/textShader.vert", "Shaders/textShader.frag");
	shader.setUniformMat4("projection", orthographic(0.0f, width, 0.0f, height, 0.0f, 2.0f));
	shader.setUniform1i("text", 0);

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void dank_text_renderer::load_font(std::string font, int font_size) {
	characters.clear();
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
		std::cout << "Error: Freetype failed to initialize." << std::endl;
	FT_Face face;
	if (FT_New_Face(ft, font.c_str(), 0, &face))
		std::cout << "Error: could not load font." << std::endl;
	FT_Set_Pixel_Sizes(face, 0, font_size);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	for (GLubyte c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "Error: could not load glyph." << std::endl;
			continue;
		}
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		dank_character character = {
			texture, 
			dank_vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			dank_vec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		characters.insert(std::pair<GLchar, dank_character>(c, character));
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}

//dank_label* dank_text_renderer::generate_label(std::string text, int x, int y, int z, int scale, dank_vec4 color) {
//	dank_label* result;
//	result->color = color;
//	for (std::string::const_iterator c = text.begin(); c != text.end(); c++) {
//		dank_character ch = characters[*c];
//		result->glyphs.push_back(dank_glyph(x, y, z, scale, ch, characters['H']));
//		x += (ch.advance >> 6) * scale;
//	}
//	return result;
//}