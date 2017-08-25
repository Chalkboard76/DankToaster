#pragma once

#include "Graphics/UI/dank_widget.h"
#include "Graphics/dank_texture_sheet.h"
#include "Graphics/dank_texture.h"
#include "Graphics/Renderers/dank_batch_renderer.h"
#include "Graphics/Renderers/dank_text_renderer.h"

class dank_chat_box : public dank_widget {
private:
	dank_texture_sheet* _sheet;
	dank_sprite* _widget_background;
public:
	dank_chat_box();
	dank_chat_box(float x, float y);
	void render();
	~dank_chat_box();
};