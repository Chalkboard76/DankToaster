#include "dank_batch_renderer_3D.h"
dank_batch_renderer_3D::dank_batch_renderer_3D() {
}
dank_batch_renderer_3D::dank_batch_renderer_3D(dank_shader* s) {
	this->shader = s;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)(offsetof(dank_vertex_textured, dank_vertex_textured::UV)));
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)(offsetof(dank_vertex_textured, dank_vertex_textured::tex_unit)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

dank_batch_renderer_3D::~dank_batch_renderer_3D() {
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
}

void dank_batch_renderer_3D::submit(dank_renderable* renderables, int count) {
	for (int i = 0; i < count; i++) {
		dank_renderable r = renderables[i];
		for (int j = 0; j < 4; j++) {
			if (j + 1 > batch_count) {
				batch_count = j + 1;
			}
			if (batches[j].submit(r)) {
				break;
			}
		}
	}
}

void dank_batch_renderer_3D::submit(std::vector<dank_sprite*>& sprites) {
	for (int i = 0; i < sprites.size(); i++) {
		for (int j = 0; j < 4; j++) {
			if (j + 1 > batch_count) {
				batch_count = j + 1;
			}
			if (batches[j].submit(*sprites[i])) {
				break;
			}
		}
	}
}

void dank_batch_renderer_3D::render() {
	shader->enable();
	for (int i = 0; i < 4; i++) {
		if (!batches[i].empty()) {
			render_batch(batches[i]);
			batches[i].clear();
		}
	}
}

void dank_batch_renderer_3D::render_batch(dank_batch& batch) {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	dank_vertex_textured* vertex = (dank_vertex_textured*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	for (int i = 0; i < batch.renderables.size(); i++) {
		dank_renderable r = batch.renderables[i];
		for (int j = 0; j < 4; j++, vertex++) {
			*vertex = r.vertices[j];
			vertex->tex_unit = batch.map[r.tex_ID];
		}
		index_count += 6;
	}

	for (int i = 0; i < batch.indices.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + batch.map[batch.indices[i]]);
		glBindTexture(GL_TEXTURE_2D, batch.indices[i]);
		batch.map[batch.indices[i]] = -1.0f;
	}

	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, NULL);
	index_count = 0;
	batch_count--;

}