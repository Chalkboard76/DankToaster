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
#include "Graphics\UI\dank_chat_box.h"
#include "Game\dank_level.h"
#include "Graphics\UI\dank_ui_layer.h"
 
int main() {
	using namespace irrklang;
	float width = 16.0f;
	float height = 9.0f;
	dank_clock c;
	dank_window window(1024, 576, "Test Window");
	ISoundEngine *SoundEngine = createIrrKlangDevice();
	dank_tile_layer tiles(width, height, 0.0f, 10000);
	dank_ui_layer ui(width, height, 1);
	text_renderer.load_font("C:\\Users\\Jacob\\files\\Projects\\DankToaster\\DankToaster\\Resources\\fonts\\consola.ttf", 50);
	dank_chat_box chat(1.0f, 1.0f, &renderer);
	dank_bar bar(100, 0, 0, dank_vec4(1, 0, 0, 1), dank_vec4(0, 0, 0, 1), dank_vec3(6, 6, 1), 4, 1);
	ui.add(&chat);
	ui.add(&bar);

	dank_texture_sheet sheet("Resources/Sheet2.png", 1, 1, .34);
	dank_level level("Resources/Maps/test.map", sheet);

	srand(time(NULL));

	glClearColor(0, 0, 0, 1);

	int frames = 0;
	double time = 0;
	std::string fps = "0";
	dank_mat4 t = translationMatrix(dank_vec3(0.1, 0, 0));
	dank_mat4 view = translationMatrix(dank_vec3(0, 0, 0));
	
	renderer.shader->setUniformMat4("view", view);
	for (int i = 0; i < level.tiles.size(); i++) {
		tiles.add(level.tiles[i]);
	}
	//SoundEngine->play2D("Resources/icecream.mp3", GL_TRUE);
	while (window.open()) {
		
		bar.increment(0.1);
		if (window.keys[GLFW_KEY_0]) {
			renderer.shader->enable();
			view.elements[12] -= 0.1;
			renderer.shader->setUniformMat4("view", view);
		}
		if (window.mouse[GLFW_MOUSE_BUTTON_LEFT]) {
			std::cout << window.cursor_x << ", " << window.cursor_y << std::endl;
		}
		time += c.tick();
		if (time >= 1.0f) {
			fps = std::to_string(frames).c_str();
			std::cout << frames << std::endl;
			frames = 0;
			time = 0;
		}
		window.clear();
		tiles.render();
		ui.render();
		text_renderer.render_text(fps.c_str(), 10, 10, 1, dank_vec3(1,1,0));
		bar.render();
		window.update();
		frames++;
	}

	return 0;
}