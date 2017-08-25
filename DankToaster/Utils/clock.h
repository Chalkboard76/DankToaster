#pragma once

class dank_clock {
public:
	dank_clock();
	~dank_clock();
	void init();
	double tick();
private:
	double _lastTime;
	double _currentTime;
};
