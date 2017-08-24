#include "dank_ui_layer.h"

dank_ui_layer::dank_ui_layer() {
}
dank_ui_layer::dank_ui_layer(float width, float height, float depth) {
	_depth = depth;
	_batch_renderer = new dank_batch_renderer(width, height);
	_square_renderer = new dank_colored_square_renderer(width, height);
	_text_renderer = new dank_text_renderer(800.0f, 450.0f);
}
dank_ui_layer::~dank_ui_layer() {
	delete _batch_renderer;
	delete _text_renderer;
	delete _square_renderer;
}

void dank_ui_layer::add(dank_widget* widget) {
	if (!widget->sprite_renderer) {
		widget->add_sprite_renderer(_batch_renderer);
	}
	if (!widget->square_renderer) {
		widget->add_square_renderer(_square_renderer);
	}
	if (!widget->text_renderer) {
		widget->add_text_renderer(_text_renderer);
	}
	_widgets.push_back(widget);
}

void dank_ui_layer::render() {
	for (int i = 0; i < _widgets.size(); i++) {
		_widgets[i]->render();
	}
}
