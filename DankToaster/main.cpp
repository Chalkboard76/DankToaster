#include "Graphics\dank_window.h"
#include "Utils\clock.h"
#include "Graphics\dank_shader.h"
#include "Graphics\dank_sprite.h"
#include "Math\dank_mat4.h"

int main() {
	clock c;
	dank_window window(1024, 576, "Testtttt");
	dank_shader shader("Shaders/spriteShader.vert", "Shaders/spriteShader.frag");
	shader.enable();
	dank_sprite test(2, 2, 5, 5, dank_vec4(1, 1, 1, 1));
	unsigned int indices[6] = { 0, 1, 3, 3, 1, 2 };
	dank_mat4 projection = orthographic(0.0f, 16.0f, 0.0f, 9.0f, 0.0f, 2.0f);
	shader.setUniformMat4("projection", projection);
	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(test.vertices), test.vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(dank_vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(dank_vertex), (const void*) offsetof(dank_vertex, dank_vertex::color));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glClearColor(1, 0, 1, 1);

	while (window.open()) {
		window.clear();
		c.tick();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		window.update();
	}
	return 0;
}