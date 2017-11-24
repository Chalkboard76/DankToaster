#include "Graphics\dank_window.h"
#include "Utils\clock.h"
#include "Graphics\dank_shader.h"
#include "Graphics\dank_sprite.h"
#include "Math\dank_mat4.h"
#include "Graphics\dank_texture_sheet.h"
#include <unordered_map>
#include <time.h>
#include "Graphics\Renderers\dank_batch_renderer.h"
#include "Graphics\Renderers\dank_text_renderer.h"
#include <irrKlang.h>
#include "Graphics\UI\dank_widget.h"
#include "Graphics\dank_tile_layer.h"
#include "Graphics\Renderers\dank_colored_square_renderer.h"
#include "Graphics\dank_colored_square.h"
#include "Graphics\UI\dank_bar.h"
#include "Graphics\UI\Chat\dank_chat_box.h"
#include "Game\dank_level.h"
#include "Graphics\UI\dank_ui_layer.h"
#include "Graphics\UI\dank_fps_counter.h"
#include "Graphics\Renderers\dank_batch_renderer_3d.h"

using namespace irrklang;
 
int main() {
#define D false
#if D == true 
	float width = 16.0f;
	float height = 9.0f;
	dank_window window(1024, 576, "Test Window");
	ISoundEngine *SoundEngine = createIrrKlangDevice();
	dank_tile_layer tiles(width, height, 0.0f, 10000);
	dank_ui_layer ui(width, height, 1);
	
	dank_chat_box chat(1.0f, 1.0f);
	dank_bar bar(100, 0, 0, dank_vec4(1, 0, 0, 1), dank_vec4(0, 0, 0, 1), dank_vec3(6, 6, 1), 4, 1);
	dank_fps_counter fps;
	ui.add(&chat);
	ui.add(&bar);
	ui.add(&fps);

	dank_texture_sheet sheet("Resources/Sheet2.png", 1, 1, .34);
	dank_level level("Resources/Maps/test.map", sheet);
	tiles.set_level(&level);
	glClearColor(0, 0, 0, 1);
	//SoundEngine->play2D("Resources/icecream.mp3", GL_TRUE);
	while (window.open()) {
		bar.increment(0.1);
		if (window.keys[GLFW_KEY_W]) {
			tiles.scroll_up(0.01);
		}
		if (window.keys[GLFW_KEY_S]) {
			tiles.scroll_down(0.01);
		}
		if (window.keys[GLFW_KEY_D]) {
			tiles.scroll_right(0.01);
		}
		if (window.keys[GLFW_KEY_A]) {
			tiles.scroll_left(0.01);
		}
		if (window.mouse[GLFW_MOUSE_BUTTON_LEFT]) {
			std::cout << window.cursor_x << ", " << window.cursor_y << std::endl;
		}

		window.clear();
		tiles.render();
		ui.render();
		window.update();
	}

	return 0;
#endif
#if !D
	float width = 16.0f;
	float height = 9.0f;
	dank_camera camera(dank_vec3(0.0f, 0.0f, -3.0f), dank_vec3(0.0f, 1.0f, 0.0f));
	dank_window window(1024, 576, "Test Window", &camera);
	ISoundEngine *SoundEngine = createIrrKlangDevice();

	dank_shader* shader = new dank_shader("Shaders/spriteShader.vert", "Shaders/spriteShader.frag");
	shader->enable();
	int texIndices[32] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	shader->setUniform1v("our_textures", texIndices, 32);

	dank_mat4 model = rotationMatrix(45.0, dank_vec3(0.0f, 0.0f, 1.0f));
	shader->setUniformMat4("model", model);
	dank_mat4 projection = perspective(45.0f, width / height, 0.1f, 100.0f);
	shader->setUniformMat4("projection", projection);
	shader->setUniformMat4("view", camera.get_view_matrix());

	dank_batch_renderer_3D renderer(shader);
	dank_texture_sheet sheet("Resources/nyoung.png", 1, 1, 1);
	dank_sprite sprite(-0.5f, -0.5f, 1.0f, 1.0f, *sheet.textures[0]);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 1);
	glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//SoundEngine->play2D("Resources/icecream.mp3", GL_TRUE);
	float amount = 0.0f;
	float cameraSpeed = 0.5f;
	float delta_time = 0.0f;
	float curr_time = 0.0f;
	float last_time = 0.0f;

	dank_text_renderer text_renderer(1380, 870);
	text_renderer.load_font("Resources/fonts/consola.ttf", 25);

	dank_vec3 mult;
	while (window.open()) {
		curr_time = glfwGetTime();
		delta_time = curr_time - last_time;
		camera.deltatime = delta_time;
		last_time = curr_time;
		if (window.keys[GLFW_KEY_W]) {
			camera.process_keyboard_input(FORWARD);
		}
		if (window.keys[GLFW_KEY_S]) {
			camera.process_keyboard_input(BACKWARD);
		}
		if (window.keys[GLFW_KEY_D]) {
			camera.process_keyboard_input(LEFT);
		}
		if (window.keys[GLFW_KEY_A]) {
			camera.process_keyboard_input(RIGHT);
		}
		if (window.mouse[GLFW_MOUSE_BUTTON_LEFT]) {
			amount++;
			model = rotationMatrix(amount, dank_vec3(1.0f, 0.0, 0.0));
		}
		shader->enable();
		renderer.shader->setUniformMat4("model", model);
		renderer.shader->setUniformMat4("view", camera.get_view_matrix());
		renderer.shader->setUniformMat4("projection", perspective(camera._zoom, width / height, 0.1f, 100.0f));
		renderer.submit(&sprite, 1);
		window.clear();
		renderer.render();
		text_renderer.render_text("Pitch: " + std::to_string(camera._pitch), 2, 2, 1, dank_vec3(1.0f, 0.0f, 1.0f));
		text_renderer.render_text("Yaw: " + std::to_string(camera._yaw), 2, 22, 1, dank_vec3(1.0f, 0.0f, 1.0f));
		window.update();
	}

	return 0;
#endif
}