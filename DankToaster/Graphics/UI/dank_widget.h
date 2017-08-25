#pragma once

#include "Graphics\dank_renderable.h"
#include <vector>
#include "Math/dank_mat4.h"
#include "Graphics\dank_sprite.h"
#include "Graphics\Renderers\dank_renderer.h"
#include "Graphics\Renderers\dank_batch_renderer.h"
#include "Graphics\Renderers\dank_colored_square_renderer.h"
#include "Graphics\Renderers\dank_text_renderer.h"


class dank_widget {
protected:
	dank_vec3 _position;
public:
	dank_batch_renderer* sprite_renderer = NULL;
	dank_colored_square_renderer* square_renderer = NULL;
	dank_text_renderer* text_renderer = NULL;
	
	dank_widget();
	dank_widget(dank_sprite* background);
	~dank_widget();

	dank_mat4 transformation;
	dank_sprite* background;
	std::vector<dank_sprite*> components;

	void add_component(dank_sprite* component);
	void transform(dank_mat4 transform);
	void add_sprite_renderer(dank_batch_renderer* renderer);
	void add_square_renderer(dank_colored_square_renderer* renderer);
	void add_text_renderer(dank_text_renderer* renderer);
	virtual void render() {
	}
	virtual void submit() {
	}
};