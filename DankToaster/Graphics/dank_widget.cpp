#include "dank_widget.h"

dank_widget::dank_widget() {

}

dank_widget::~dank_widget() {

}

dank_widget::dank_widget(dank_sprite* widget_background, dank_renderer* renderer) {
	_position.x = widget_background->vertices[0].position.x;
	_position.y = widget_background->vertices[0].position.y;
	_renderer = renderer;

	background = widget_background;
	transformation = translationMatrix(dank_vec3(_position.x, _position.y, 0.0f));
}

void dank_widget::transform(dank_mat4 transform) {
	transformation = transform * transformation;
	_position = transform * _position;
	for (int i = 0; i < 4; i++) {
		background->vertices[i].position = transform * background->vertices[i].position;
	}
	for (int i = 0; i < components.size(); i++) {
		for (int j = 0; j < 4; j++) {
			components[i]->vertices[j].position = transform * components[i]->vertices[j].position;
		}
	}
}

void dank_widget::add_component(dank_sprite* component) {
	for (int i = 0; i < 4; i++) {
		component->vertices[i].position = transformation * component->vertices[i].position;
	}
	components.push_back(component);
}
