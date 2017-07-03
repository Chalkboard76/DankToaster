#pragma once

#include <GL\glew.h>
#include <unordered_map>
#include "dank_character.h"
#include "dank_shader.h"
#include "Math\dank_vec4.h"
#include "dank_label.h"


class dank_text_renderer {
#define MAX_GLYPHS				500
#define GLYPH_VERTEX_SIZE		sizeof(dank_glyph)
#define GLYPH_SIZE				4 * GLYPH_VERTEX_SIZE
#define NUM_INDICES				6 * MAX_GLYPHS
#define BUFFER_SIZE				MAX_GLYPHS * GLYPH_SIZE


private:
	GLuint _VAO, _VBO, _EBO;
public:

	std::unordered_map<GLchar, dank_character> characters;
	dank_shader shader;

	dank_text_renderer(int width, int height);
	~dank_text_renderer();
	
	void load_font(std::string font, int font_size);
	void render_text(std::string text, int x, int y, int scale, dank_vec4 color);
	dank_label* generate_label(std::string text, int x, int y, int z, int scale, dank_vec4 color);
	void render_label(dank_label label);

};