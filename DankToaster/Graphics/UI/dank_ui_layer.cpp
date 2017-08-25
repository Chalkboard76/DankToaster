#include "dank_ui_layer.h"

dank_ui_layer::dank_ui_layer() {
}

/* Initializes renderers. Initializes text renderer font to be consolas. */
dank_ui_layer::dank_ui_layer(float width, float height, float depth) {
	_depth = depth;
	_sprite_renderer = new dank_batch_renderer(width, height);
	_square_renderer = new dank_colored_square_renderer(width, height);
	_text_renderer = new dank_text_renderer(800.0f, 450.0f);
	_text_renderer->load_font("C:\\Users\\Jacob\\files\\Projects\\DankToaster\\DankToaster\\Resources\\fonts\\consola.ttf", 50);
}
dank_ui_layer::~dank_ui_layer() {
	delete _sprite_renderer;
	delete _text_renderer;
	delete _square_renderer;
}

/* Checks if the widget already has a renderer or not. 
Provides the UI layer's renderers if not. Adds widget to
the UI layer's vector of widgets. */
void dank_ui_layer::add(dank_widget* widget) {
	if (!widget->sprite_renderer) {
		widget->add_sprite_renderer(_sprite_renderer);
	}
	if (!widget->square_renderer) {
		widget->add_square_renderer(_square_renderer);
	}
	if (!widget->text_renderer) {
		widget->add_text_renderer(_text_renderer);
	}
	_widgets.push_back(widget);
}

/* Calls each widget's render function. */
void dank_ui_layer::render() {
	for (int i = 0; i < _widgets.size(); i++) {
		_widgets[i]->submit();
	}
	if (_sprite_renderer->batch_count) {
		_sprite_renderer->render();
	}
	if(_square_renderer.)
	
}
