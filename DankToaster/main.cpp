#include "Graphics\dank_window.h"
#include "Utils\clock.h"
#include "Graphics\dank_shader.h"
#include "Graphics\dank_sprite.h"
#include "Math\dank_mat4.h"
#include "Graphics\dank_texture_sheet.h"
#include <unordered_map>
#include <time.h>
#include "Graphics\dank_batch_renderer.h"

int main() {
	dank_clock c;
	dank_window window(1024, 576, "Testtttt");
	dank_shader shader("Shaders/spriteShader.vert", "Shaders/spriteShader.frag");
	dank_batch_renderer renderer;
	
	dank_texture_sheet sheets[34] = {
		dank_texture_sheet("Resources/test/tex1.png"),
		dank_texture_sheet("Resources/test/tex2.png"),
		dank_texture_sheet("Resources/test/tex3.png"),
		dank_texture_sheet("Resources/test/tex4.png"),
		dank_texture_sheet("Resources/test/tex5.png"),
		dank_texture_sheet("Resources/test/tex6.png"),
		dank_texture_sheet("Resources/test/tex7.png"),
		dank_texture_sheet("Resources/test/tex8.png"),
		dank_texture_sheet("Resources/test/tex9.png"),
		dank_texture_sheet("Resources/test/tex10.png"),
		dank_texture_sheet("Resources/test/tex11.png"),
		dank_texture_sheet("Resources/test/tex12.png"),
		dank_texture_sheet("Resources/test/tex13.png"),
		dank_texture_sheet("Resources/test/tex14.png"),
		dank_texture_sheet("Resources/test/tex15.png"),
		dank_texture_sheet("Resources/test/tex16.png"),
		dank_texture_sheet("Resources/test/tex17.png"),
		dank_texture_sheet("Resources/test/tex18.png"),
		dank_texture_sheet("Resources/test/tex19.png"),
		dank_texture_sheet("Resources/test/tex20.png"),
		dank_texture_sheet("Resources/test/tex21.png"),
		dank_texture_sheet("Resources/test/tex22.png"),
		dank_texture_sheet("Resources/test/tex23.png"),
		dank_texture_sheet("Resources/test/tex24.png"),
		dank_texture_sheet("Resources/test/tex25.png"),
		dank_texture_sheet("Resources/test/tex26.png"),
		dank_texture_sheet("Resources/test/tex27.png"),
		dank_texture_sheet("Resources/test/tex28.png"),
		dank_texture_sheet("Resources/test/tex29.png"),
		dank_texture_sheet("Resources/test/tex30.png"),
		dank_texture_sheet("Resources/test/tex31.png"),
		dank_texture_sheet("Resources/test/tex32.png"),
		dank_texture_sheet("Resources/test/tex33.png"),
		dank_texture_sheet("Resources/test/tex34.png")
	};
	dank_texture textures[34];
	for (int i = 0; i < 34; i++) {
		textures[i] = dank_texture(sheets[i], dank_vec2(0, 0), 1, 1);
	}
	dank_sprite* sprites = new dank_sprite[10000];
	int sprite_count = 0;
	srand(time(NULL));
	for (float y = 0.0f; y < 9.0f; y += 1.0f) {
		for (float x = 0.0f; x < 16.0f; x += 1.0f) {
			sprites[sprite_count] = dank_sprite(x, y, 0.99f, 0.99f, textures[sprite_count % 34]);
			sprite_count++;
		}
	}

	
	shader.enable();
	float texIndices[32] = { 0.0f,1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f,13.0f,14.0f,15.0f,16.0f,17.0f,18.0f,19.0f,20.0f,21.0f,22.0f,23.0f,24.0f,25.0f,26.0f,27.0f,28.0f,29.0f,30.0f,31.0f };
	dank_mat4 projection = orthographic(0.0f, 16.0f, 0.0f, 9.0f, 0.0f, 2.0f);
	shader.setUniformMat4("projection", projection);
	shader.setUniform1fv("our_textures", texIndices, 32);
	glClearColor(1, 1, 1, 1);

	while (window.open()) {
		window.clear();
		c.tick();
		renderer.submit(sprites, sprite_count);
		renderer.render();
		window.update();
	}

	delete[] sprites;
	return 0;
}