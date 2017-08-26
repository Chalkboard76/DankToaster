#pragma once

#include "dank_widget.h"
#include "Utils/clock.h"
#include <string.h>

class dank_fps_counter : public dank_widget {
private:
	dank_clock* clock;
	int frames;
	double time;
	std::string fps;
public:
	dank_fps_counter();
	~dank_fps_counter();

	void init();
	void tick();
	virtual void render();
	virtual void submit();
};