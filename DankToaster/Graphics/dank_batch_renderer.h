#pragma once
#include "dank_renderable.h"
#include <GL\glew.h>
#include "dank_vertex.h"
#include "dank_batch.h"

struct dank_batch_renderer {
	#define MAX_RENDERABLES		5000
	#define VERTEX_SIZE			sizeof(dank_vertex)
	#define RENDERABLE_SIZE		VERTEX_SIZE * 4
	#define BUFFER_SIZE			RENDERABLE_SIZE * MAX_RENDERABLES
	#define NUM_INDICES			MAX_RENDERABLES * 6

	GLuint VAO, VBO, EBO;
	dank_batch batches[4];
	int batch_count;
	unsigned int index_count;

	dank_batch_renderer();
	~dank_batch_renderer();
	void submit(dank_renderable* renderables, int count);
	void render_batch(dank_batch& batch);
	void render();
};