#pragma once

#include "Graphics\dank_shader.h"
#include "Graphics\Renderers\dank_batch_renderer.h"
#include "Graphics\dank_sprite.h"
#include "dank_widget.h"
#include <vector>
#include "Graphics\Renderers\dank_text_renderer.h"
#include "Graphics\Renderers\dank_colored_square_renderer.h"

class dank_ui_layer {
private:
	float _depth;
	std::vector<dank_widget*> _widgets;
	dank_batch_renderer* _sprite_renderer;
	dank_colored_square_renderer* _square_renderer;
	dank_text_renderer* _text_renderer;
public:
	dank_ui_layer();
	dank_ui_layer(float width, float height, float depth);
	~dank_ui_layer();

	void add(dank_widget* widget);
	void render();
};