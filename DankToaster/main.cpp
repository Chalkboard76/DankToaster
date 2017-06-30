#include "Graphics\dank_window.h"
#include "Utils\clock.h"
#include "Graphics\dank_shader.h"
#include "Graphics\dank_sprite.h"
#include "Math\dank_mat4.h"
#include "Graphics\dank_texture_sheet.h"

int main() {
	clock c;
	dank_window window(1024, 576, "Testtttt");
	dank_shader shader("Shaders/spriteShader.vert", "Shaders/spriteShader.frag");
	dank_texture_sheet sheet1("Resources/Sheet1.png");
	dank_texture_sheet sheet2("Resources/Sheet2.png");
	dank_texture tex1(sheet1, dank_vec2(0, 0), 1.0f / 5.0f, 1.0f / 5.0f);
	dank_texture tex2(sheet2, dank_vec2(1.0f / 5.0f, 1.0f / 5.0f), 1.0f / 5.0f, 1.0f / 5.0f);
	dank_sprite sprite1(1, 1, 3, 3, tex1);
	dank_sprite sprite2(5, 5, 3, 3, tex2);
	shader.enable();
	unsigned int indices[6] = { 0, 1, 3, 3, 1, 2 };
	float texIndices[32] = { 0.0f,1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f,13.0f,14.0f,15.0f,16.0f,17.0f,18.0f,19.0f,20.0f,21.0f,22.0f,23.0f,24.0f,25.0f,26.0f,27.0f,28.0f,29.0f,30.0f,31.0f };
	dank_mat4 projection = orthographic(0.0f, 16.0f, 0.0f, 9.0f, 0.0f, 2.0f);
	shader.setUniformMat4("projection", projection);
	shader.setUniform1fv("our_textures", texIndices, 32);
	
	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sprite1.vertices), sprite1.vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(dank_vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(dank_vertex), (const void*)offsetof(dank_vertex, dank_vertex::UV));
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(dank_vertex), (const void*)offsetof(dank_vertex, dank_vertex::texID));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glClearColor(1, 0, 1, 1);

	while (window.open()) {
		window.clear();
		c.tick();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sprite1.vertices[0].texID);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		window.update();
	}
	return 0;
}