#pragma once

#include "dank_renderable.h"
#include <GL\glew.h>
#include "dank_vertex.h"
#include "dank_batch.h"
#include "dank_shader.h"
#include "dank_sprite.h"
#include "dank_renderer.h"

struct dank_batch_renderer : dank_renderer {
	const static int MAX_RENDERABLES = 5000;
	const static int VERTEX_SIZE = sizeof(dank_vertex);
	const static int RENDERABLE_SIZE = VERTEX_SIZE * 4;
	const static int BUFFER_SIZE = RENDERABLE_SIZE * MAX_RENDERABLES;
	const static int NUM_INDICES = MAX_RENDERABLES * 6;

	GLuint			VAO, VBO, EBO;
	dank_batch		batches[4];
	int				batch_count;
	unsigned int	index_count;
	dank_shader		shader;

	dank_batch_renderer();
	dank_batch_renderer(float width, float height);
	~dank_batch_renderer();
	void submit(dank_renderable* renderables, int count);
	void submit(std::vector<dank_sprite*> sprites);
	void render_batch(dank_batch& batch);
	void render();
};