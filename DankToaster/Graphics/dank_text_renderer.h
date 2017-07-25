#pragma once

#include <GL\glew.h>
#include <unordered_map>
#include "dank_character.h"
#include "dank_shader.h"
#include "Math\dank_vec4.h"
#include "dank_label.h"


class dank_text_renderer {
	const static int MAX_GLYPHS = 500;
	const static int GLYPH_VERTEX_SIZE = sizeof(dank_glyph);
	const static int GLYPH_SIZE = 4 * GLYPH_VERTEX_SIZE;
	const static int NUM_INDICES = 6 * MAX_GLYPHS;
	const static int BUFFER_SIZE = MAX_GLYPHS * GLYPH_SIZE;

private:
	GLuint _VAO, _VBO, _EBO;
public:

	std::unordered_map<GLchar, dank_character> characters;
	dank_shader shader;

	dank_text_renderer(int width, int height);
	~dank_text_renderer();
	
	void load_font(std::string font, int font_size);
	void generate_label(dank_label* label, std::string text, int x, int y, int z, int scale, dank_vec4 color);
	void render_label(dank_label label);
	void render_text(std::string text, int x, int y, int scale, dank_vec3 color);

};