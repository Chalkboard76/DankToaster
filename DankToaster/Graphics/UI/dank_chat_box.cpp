#include "dank_chat_box.h"

dank_chat_box::dank_chat_box(float x, float y) {
	_sheet = new dank_texture_sheet("Resources//textboxbackground.png", 1, 1, 1);
	_widget_background = new dank_sprite(x, y, 4.8f, 2.7f, *_sheet->textures[0]);
	_position.x = _widget_background->vertices[0].position.x;
	_position.y = _widget_background->vertices[0].position.y;

	background = _widget_background;
	transformation = translationMatrix(dank_vec3(_position.x, _position.y, 0.0f));
}

dank_chat_box::~dank_chat_box() {
	delete _widget_background;
	delete _sheet;
}

/*
DOES NOT ACTUALLY RENDER. The renderer is external, thus its render function should
be called externally as well. This function just sends the necessary information to
the appropriate renderers.
*/
void dank_chat_box::render() {
	sprite_renderer->submit(_widget_background, 1);
}