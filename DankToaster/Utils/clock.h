#pragma once

class dank_clock {
public:
	dank_clock();
	~dank_clock();
	void tick();
private:
	double _lastTime;
	double _currentTime;
	int _frames;
};
