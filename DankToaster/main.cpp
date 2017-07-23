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

int main() {
	using namespace irrklang;
	dank_clock c;
	dank_window window(1024, 576, "Testtttt");
	dank_shader shader();
	dank_batch_renderer renderer(16.0f, 9.0f);
	dank_text_renderer text_renderer(800.0f, 450.0f);
	text_renderer.load_font("C:\\Users\\Jacob\\files\\Projects\\DankToaster\\DankToaster\\Resources\\fonts\\consola.ttf", 50);
	ISoundEngine *SoundEngine = createIrrKlangDevice();

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
	for (float y = 0.0f; y < 9.0f; y += 0.25f) {
		for (float x = 0.0f; x < 16.0f; x += 0.25f) {
			sprites[sprite_count] = dank_sprite(x, y, 0.24f, 0.24f, textures[sprite_count % 34]);
			sprite_count++;
		}
	}

	dank_sprite UI(1,1,4,4,textures[0]);
	dank_sprite button(1, 1, 1, 1, textures[1]);
	dank_widget widget(&UI);
	widget.add_component(&button);

	glClearColor(0, 0, 0, 1);

	int frames = 0;
	double time = 0;
	std::string fps = "0";
	//SoundEngine->play2D("Resources/icecream.mp3", GL_TRUE);
	dank_mat4 t = translationMatrix(dank_vec3(0.01, 0, 0));
	widget.transform(t);
	while (window.open()) {
		if (window.keys[GLFW_KEY_0]) {
			widget.transform(t);
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
		renderer.submit(sprites, sprite_count);
		renderer.render();
		renderer.submit(widget.background, 1);
		renderer.submit(widget.components[0], 1);
		renderer.render();
		text_renderer.render_text(fps.c_str(), 10, 10, 1, dank_vec3(1,1,0));
		window.update();
		frames++;
	}

	return 0;
}