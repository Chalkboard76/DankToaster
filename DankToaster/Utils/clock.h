#pragma once

class Clock {
public:
	Clock();
	~Clock();
	double tick();
private:
	double _lastTime;
	double _currentTime;
	int _frames;
};
