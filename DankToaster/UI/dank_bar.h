#pragma once

class dank_bar {
private:
	float _variable;
	float _maximum;
	float _minimum;
public:
	dank_bar();
	dank_bar(float _maximum, float minimum, float initial_value);
	~dank_bar();
};