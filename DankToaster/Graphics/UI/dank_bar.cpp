#include "dank_bar.h"

dank_bar::dank_bar() {
}


dank_bar::dank_bar(dank_colored_square_renderer* renderer, float maximum, float minimum, float initial_value,
	dank_vec4& color, dank_vec4& color2, dank_vec3& position, float width, float height) {
	square_renderer = renderer;
	_maximum = maximum;
	_minimum = minimum;
	_variable = initial_value;
	_color = color;
	_color2 = color2;
	_position = position;
	_width = width;
	_height = height;

	squares.push_back(new dank_colored_square(position.x, position.y, width, height, _color2));
	squares.push_back(new dank_colored_square(position.x, position.y, initial_value / (maximum - minimum) * width, height, _color));
}

dank_bar::dank_bar(float maximum, float minimum, float initial_value,
	dank_vec4& color, dank_vec4& color2, dank_vec3& position, float width, float height) {
	_maximum = maximum;
	_minimum = minimum;
	_variable = initial_value;
	_color = color;
	_color2 = color2;
	_position = position;
	_width = width;
	_height = height;

	squares.push_back(new dank_colored_square(position.x, position.y, width, height, _color2));
	squares.push_back(new dank_colored_square(position.x, position.y, initial_value / (maximum - minimum) * width, height, _color));
}

dank_bar::~dank_bar() {
	delete squares[0];
	delete squares[1];
}

void dank_bar::render() {
}

void dank_bar::submit() {
	square_renderer->submit(squares);
}

void dank_bar::decrement(float value) {
	if (_variable > _minimum) {
		_variable -= value;
		float chunk_lost = value / (_maximum - _minimum) * _width;
		squares[1]->vertices[1].position.x -= chunk_lost;
		squares[1]->vertices[2].position.x -= chunk_lost;
	}
}

void dank_bar::increment(float value) {
	if (_variable < _maximum) {
		_variable += value;
		float chunk_gained = value / (_maximum - _minimum) * _width;
		squares[1]->vertices[1].position.x += chunk_gained;
		squares[1]->vertices[2].position.x += chunk_gained;
	}
}