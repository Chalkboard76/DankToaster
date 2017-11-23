#pragma once

#include "Graphics\dank_renderable.h"
#include <GL\glew.h>
#include "Graphics\dank_vertex_textured.h"
#include "Graphics\dank_batch.h"
#include "Graphics\dank_shader.h"
#include "Graphics\dank_sprite.h"
#include "dank_renderer.h"

struct dank_batch_renderer_3D : public dank_renderer {
	const static int MAX_RENDERABLES = 5000;
	const static int VERTEX_SIZE = sizeof(dank_vertex_textured);
	const static int RENDERABLE_SIZE = VERTEX_SIZE * 4;
	const static int BUFFER_SIZE = RENDERABLE_SIZE * MAX_RENDERABLES;
	const static int NUM_INDICES = MAX_RENDERABLES * 6;

	GLuint			VAO, VBO, EBO;
	dank_batch		batches[4];
	int				batch_count;
	unsigned int	index_count;
	dank_shader*	shader;
	dank_mat4		view;

	dank_batch_renderer_3D();
	dank_batch_renderer_3D(dank_shader* shader);
	~dank_batch_renderer_3D();
	void submit(dank_renderable* renderables, int count);
	void submit(std::vector<dank_sprite*>& sprites);
	void render_batch(dank_batch& batch);
	void render();
};