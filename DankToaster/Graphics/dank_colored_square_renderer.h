#pragma once
#include "dank_vertex_colored.h"
#include <gl\glew.h>
#include "dank_shader.h"
#include "dank_colored_square.h"
#include <vector>
#include "dank_renderer.h"

class dank_colored_square_renderer : dank_renderer {
private:
	const static int MAX_RENDERABLES = 1000;
	const static int VERTEX_SIZE = sizeof(dank_vertex_colored);
	const static int RENDERABLE_SIZE = VERTEX_SIZE * 4;
	const static int BUFFER_SIZE = RENDERABLE_SIZE * MAX_RENDERABLES;
	const static int NUM_INDICES = MAX_RENDERABLES * 6;

	GLuint			_VAO, _VBO, _EBO;
	unsigned int	_index_count;
	dank_shader		_shader;
	std::vector<dank_colored_square*> _squares;
public:
	dank_colored_square_renderer();
	dank_colored_square_renderer(float width, float height);
	~dank_colored_square_renderer();
	void submit(dank_colored_square* square, int count);
	void submit(std::vector<dank_colored_square*> sprites);
	void render();
};