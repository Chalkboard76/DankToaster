#include "dank_text_renderer.h"
#include <cstdint>
#include <ft2build.h>
#include FT_FREETYPE_H

dank_text_renderer::dank_text_renderer(int width, int height) {
	shader = new dank_shader("Shaders/textShader.vert", "Shaders/textShader.frag");
	shader->enable();
	shader->setUniformMat4("projection", orthographic(0.0f, width, 0.0f, height, 0.0f, 2.0f));
	shader->setUniform1i("text", 0);

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

dank_text_renderer::~dank_text_renderer() {
	delete shader;
}

void dank_text_renderer::load_font(std::string font, int font_size) {
	characters.clear();
	FT_Library library;
	if (FT_Init_FreeType(&library))
		std::cout << "Error: Freetype failed to initialize." << std::endl;
	FT_Face face;
	if (FT_New_Face(library, font.c_str(), 0, &face))
		std::cout << "Error: could not load font." << std::endl;
	FT_Set_Pixel_Sizes(face, 0, font_size);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	for (GLubyte c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "Error: could not load face." << std::endl;
			continue;
		}
		int glyph_index = FT_Get_Char_Index(face, c);
		/*if (FT_Load_Glyph(face, glyph_index, 0)) {
			std::cout << "Error: could not load glyph." << std::endl;
		}
		if (FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL)) {
			std::cout << "Error: could not render glyph." << std::endl;
		}*/
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		/*for (uint8_t i = 0; i < face->glyph->bitmap.rows * face->glyph->bitmap.width; i++) {
			std::cout << int(face->glyph->bitmap.buffer[i]) << std::endl;
		}*/
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
	FT_Done_FreeType(library);
}

void dank_text_renderer::generate_label(dank_label* label, std::string text, int x, int y, int z, int scale, dank_vec4 color) {
	label->color = color;
	for (std::string::const_iterator c = text.begin(); c != text.end(); c++) {
		dank_character ch = characters[*c];
		label->glyphs.push_back(dank_glyph(x, y, z, scale, ch, characters['H']));
		x += (ch.advance >> 6) * scale;
	}
}

void dank_text_renderer::render_label(dank_label label) {

}

void dank_text_renderer::render_text(std::string text, int x, int y, float scale, dank_vec3 color) {
	shader->enable();
	shader->setUniform3f("textColor", color);
	glBindVertexArray(_VAO);

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		dank_character ch = characters[*c];

		GLfloat xpos = x + ch.bearing.x * scale;
		GLfloat ypos = y + (characters['H'].bearing.y - ch.bearing.y) * scale;

		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 0.0 },
			{ xpos,     ypos,       0.0, 0.0 },

			{ xpos,     ypos + h,   0.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 1.0 },
			{ xpos + w, ypos,       1.0, 0.0 }
		};
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, ch.tex_ID);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

		glBindBuffer(GL_ARRAY_BUFFER, 0); 
		glDrawArrays(GL_TRIANGLES, 0, 6);
		x += (ch.advance >> 6) * scale;
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}