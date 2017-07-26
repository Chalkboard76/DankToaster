#pragma once

#include "Graphics\dank_widget.h"
#include "Graphics\dank_colored_square_renderer.h"

class dank_bar : dank_widget {
private:
	dank_colored_square_renderer* _renderer;
	float _variable;
	float _maximum;
	float _minimum;
	dank_vec4 _color;
	dank_vec4 _color2;

	float _width;
	float _height;

	std::vector<dank_colored_square*> squares;
public:
	dank_bar();
	dank_bar(dank_colored_square_renderer* renderer, float _maximum, float minimum, float initial_value,
		dank_vec4& color, dank_vec4& color2, dank_vec3& position, float width, float height);
	~dank_bar();

	void render();
	void decrement(float value);
	void increment(float value);
};