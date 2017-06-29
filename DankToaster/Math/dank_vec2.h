#pragma once
#include <iostream>

struct dank_vec2 {
	float x, y;

	dank_vec2();
	dank_vec2(const float& x, const float& y);

	float length();

	dank_vec2& add(const float& scalar);
	dank_vec2& subtract(const float& scalar);
	dank_vec2& multiply(const float& scalar);
	dank_vec2& divide(const float& scalar);

	dank_vec2& add(const dank_vec2& vector);
	dank_vec2& subtract(const dank_vec2& vector);
	dank_vec2& multiply(const dank_vec2& vector);
	dank_vec2& divide(const dank_vec2& vector);

	dank_vec2& operator+(const float& scalar);
	dank_vec2& operator-(const float& scalar);
	dank_vec2& operator*(const float& scalar);
	dank_vec2& operator/(const float& scalar);

	dank_vec2& operator+(const dank_vec2& vector);
	dank_vec2& operator-(const dank_vec2& vector);
	dank_vec2& operator*(const dank_vec2& vector);
	dank_vec2& operator/(const dank_vec2& vector);

	dank_vec2& operator+=(const float& scalar);
	dank_vec2& operator-=(const float& scalar);
	dank_vec2& operator*=(const float& scalar);
	dank_vec2& operator/=(const float& scalar);

	dank_vec2& operator+=(const dank_vec2& vector);
	dank_vec2& operator-=(const dank_vec2& vector);
	dank_vec2& operator*=(const dank_vec2& vector);
	dank_vec2& operator/=(const dank_vec2& vector);

	bool operator==(const dank_vec2& vector);
	bool operator!=(const dank_vec2& vector);

	friend std::ostream& operator<<(std::ostream& os, const dank_vec2& vector);
};
