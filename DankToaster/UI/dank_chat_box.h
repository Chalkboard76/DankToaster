#pragma once

#include "Graphics/dank_widget.h"
#include "Graphics/dank_texture_sheet.h"
#include "Graphics/dank_texture.h"
#include "Graphics/dank_batch_renderer.h"
#include "Graphics/dank_text_renderer.h"

class dank_chat_box : public dank_widget {
private:
	dank_batch_renderer* _renderer;
	dank_text_renderer* _text_renderer;
	dank_texture_sheet* _sheet;
	dank_sprite* _widget_background;
public:
	dank_chat_box();
	dank_chat_box(float x, float y, dank_batch_renderer* renderer);
	void render();
	~dank_chat_box();
};