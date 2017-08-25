#include "dank_fps_counter.h"

dank_fps_counter::dank_fps_counter() {
	clock = new dank_clock();
	frames = 0;
	time = 0;
	fps = "0";
}

dank_fps_counter::~dank_fps_counter() {
	delete clock;
}

/* Initialize before the game loop. */
void dank_fps_counter::init() {
	clock->init();
}

/* Intended to be used inside of the game loop. Will guage
how many frames per second the loop is running at. */
void dank_fps_counter::tick() {
	frames++;
	time += clock->tick();
	if (time >= 1.0f) {
		fps = std::to_string(frames).c_str();
		std::cout << frames << std::endl;
		frames = 0;
		time = 0;
	}
}

/* Handles ticking of clock and mathematical calculation of fps.
Then renders using the UI layers text renderer. */
void dank_fps_counter::render() {
	tick();
	text_renderer->render_text(fps.c_str(), 10, 10, 1, dank_vec3(1, 1, 0));
}