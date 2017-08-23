#include "dank_ui_layer.h"

dank_ui_layer::dank_ui_layer() {
}
dank_ui_layer::dank_ui_layer(float depth) {
	_depth = depth;
}
dank_ui_layer::~dank_ui_layer() {
}

void dank_ui_layer::add(dank_widget* widget) {
	_widgets.push_back(widget);
}

void dank_ui_layer::render() {
	for (int i = 0; i < _widgets.size(); i++) {
		_widgets[i]->render();
	}
}
