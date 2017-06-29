#pragma once

class clock {
public:
	clock();
	~clock();
	void tick();
private:
	double _lastTime;
	double _currentTime;
	int _frames;
};
