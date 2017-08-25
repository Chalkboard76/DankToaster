#include "dank_colored_square_renderer.h"

dank_colored_square_renderer::dank_colored_square_renderer() {

}
dank_colored_square_renderer::dank_colored_square_renderer(float width, float height) {
	_shader.init("Shaders/squareShader.vert", "Shaders/squareShader.frag");
	dank_mat4 projection = orthographic(0.0f, width, 0.0f, height, -2.0f, 2.0f);
	_shader.enable();
	_shader.setUniformMat4("projection", projection);
	
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glGenBuffers(1, &_EBO);

	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)(offsetof(dank_vertex_colored, dank_vertex_colored::color)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	int indices[NUM_INDICES];
	GLuint offset = 0;
	for (int i = 0; i < NUM_INDICES; i += 6) {
		indices[i] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;
		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 3;
		indices[i + 5] = offset + 0;
		offset += 4;
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
dank_colored_square_renderer::~dank_colored_square_renderer() {

}

void dank_colored_square_renderer::submit(dank_colored_square* squares, int count) {
	for (int i = 0; i < count; i++) {
		_squares.push_back(&squares[i]);
	}
}

void dank_colored_square_renderer::submit(std::vector<dank_colored_square*> squares) {
	for (int i = 0; i < squares.size(); i++) {
		_squares.push_back(squares[i]);
	}
}

void dank_colored_square_renderer::render() {
	_shader.enable();
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	dank_vertex_colored* vertex = (dank_vertex_colored*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	for (int i = 0; i < _squares.size(); i++) {
		dank_colored_square* s = _squares[i];
		for (int j = 0; j < 4; j++, vertex++) {
			*vertex = s->vertices[j];
		}
		_index_count += 6;
	}

	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, _index_count, GL_UNSIGNED_INT, NULL);
	_index_count = 0;
	_squares.clear();
}

