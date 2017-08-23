#include "Graphics\dank_window.h"
#include "Utils\clock.h"
#include "Graphics\dank_shader.h"
#include "Graphics\dank_sprite.h"
#include "Math\dank_mat4.h"
#include "Graphics\dank_texture_sheet.h"
#include <unordered_map>
#include <time.h>
#include "Graphics\dank_batch_renderer.h"
#include "Graphics\dank_text_renderer.h"
#include <irrKlang.h>
#include "Graphics\dank_widget.h"
#include "Graphics\dank_tile_layer.h"
#include "Graphics\dank_colored_square_renderer.h"
#include "Graphics\dank_colored_square.h"
#include "UI\dank_bar.h"
#include "UI\dank_chat_box.h"
#include "Game\dank_level.h"
#include "Graphics\dank_ui_layer.h"
 
int main() {
	using namespace irrklang;
	dank_clock c;
	dank_window window(1024, 576, "Testtttt");
	dank_batch_renderer renderer(16.0f, 9.0f);
	dank_text_renderer text_renderer(800.0f, 450.0f);
	text_renderer.load_font("C:\\Users\\Jacob\\files\\Projects\\DankToaster\\DankToaster\\Resources\\fonts\\consola.ttf", 50);
	ISoundEngine *SoundEngine = createIrrKlangDevice();
	dank_tile_layer tiles(&renderer, 0.0f, 10000);
	dank_colored_square_renderer square_renderer(16.0f, 9.0f);
	dank_colored_square test_square(0.15,0.15,1.75,.75,dank_vec4(0,0,0,0.75));
	dank_bar bar(&square_renderer, 100, 0, 0, dank_vec4(1, 0, 0, 1), dank_vec4(0, 0, 0, 1), dank_vec3(6, 6, 1), 4, 1);
	dank_texture_sheet sheet("Resources/Sheet2.png", 1, 1, .34);
	dank_ui_layer ui(1);
	dank_chat_box chat(1.0f, 1.0f, &renderer);
	ui.add(&chat);


	/*dank_sprite s1(0.0f, 0.0f, 1.0f, 1.0f, *sheet.textures[0]);
	dank_sprite s2(0.0f, 1.0f, 1.0f, 1.0f, *sheet.textures[1]);
	dank_sprite s3(0.0f, 2.0f, 1.0f, 1.0f, *sheet.textures[2]);
	dank_sprite s4(0.0f, 3.0f, 1.0f, 1.0f, *sheet.textures[3]);
	dank_sprite s5(0.0f, 4.0f, 1.0f, 1.0f, *sheet.textures[4]);
	dank_sprite s6(0.0f, 5.0f, 1.0f, 1.0f, *sheet.textures[5]);
	dank_sprite s7(0.0f, 6.0f, 1.0f, 1.0f, *sheet.textures[6]);
	dank_sprite s8(0.0f, 7.0f, 1.0f, 1.0f, *sheet.textures[7]);
	dank_sprite s9(0.0f, 8.0f, 1.0f, 1.0f, *sheet.textures[8]);


	tiles.add(&s1);
	tiles.add(&s2);
	tiles.add(&s3);
	tiles.add(&s4);
	tiles.add(&s5);
	tiles.add(&s6);
	tiles.add(&s7);
	tiles.add(&s8);
	tiles.add(&s9);*/

	dank_level level("Resources/Maps/test.map", sheet);

	srand(time(NULL));

	glClearColor(0, 0, 0, 1);

	int frames = 0;
	double time = 0;
	std::string fps = "0";
	//SoundEngine->play2D("Resources/icecream.mp3", GL_TRUE);
	dank_mat4 t = translationMatrix(dank_vec3(0.1, 0, 0));

	dank_mat4 view = translationMatrix(dank_vec3(0, 0, 0));
	renderer.shader->setUniformMat4("view", view);
	for (int i = 0; i < level.tiles.size(); i++) {
		tiles.add(level.tiles[i]);
	}
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
		renderer.render();
		square_renderer.submit(&test_square, 1);
		square_renderer.render();
		text_renderer.render_text(fps.c_str(), 10, 10, 1, dank_vec3(1,1,0));
		bar.render();
		window.update();
		frames++;
	}

	return 0;
}