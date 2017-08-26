#pragma once

#include "Graphics\UI\dank_widget.h"
#include "Graphics\Renderers\dank_colored_square_renderer.h"

class dank_bar : public dank_widget {
private:
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
	dank_bar(float _maximum, float minimum, float initial_value,
		dank_vec4& color, dank_vec4& color2, dank_vec3& position, float width, float height);

	~dank_bar();

	void render();
	virtual void submit();
	void decrement(float value);
	void increment(float value);
};