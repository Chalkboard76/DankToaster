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
	dank_window window(1024, 576, "Test Window");
	ISoundEngine *SoundEngine = createIrrKlangDevice();
	dank_batch_renderer_3D renderer(width, height);
	dank_mat4 model = rotationMatrix(-55.0, dank_vec3(1.0f, 0.0, 0.0));
	renderer.shader->setUniformMat4("model", model);
	dank_mat4 view = translationMatrix(dank_vec3(0.0f, 0.0f, -3.0f));
	renderer.shader->setUniformMat4("view", view);
	dank_texture_sheet sheet("Resources/nyoung.png", 1, 1, 1);
	dank_sprite sprite(-0.5f, 0.5f, 1.0f, 1.0f, *sheet.textures[0]);
	glClearColor(0, 0, 0, 1);
	//SoundEngine->play2D("Resources/icecream.mp3", GL_TRUE);
	float amount = 0.0f;
	while (window.open()) {
		if (window.keys[GLFW_KEY_W]) {
			amount++;
			model = rotationMatrix(-55.0 + amount, dank_vec3(1.0f, 0.0, 0.0));
			renderer.shader->setUniformMat4("model", model);
		}
		if (window.keys[GLFW_KEY_S]) {
		}
		if (window.keys[GLFW_KEY_D]) {
		}
		if (window.keys[GLFW_KEY_A]) {
		}
		if (window.mouse[GLFW_MOUSE_BUTTON_LEFT]) {
		}
		renderer.submit(&sprite, 1);
		window.clear();
		renderer.render();
		window.update();
	}

	return 0;
#endif
}