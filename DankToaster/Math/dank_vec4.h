#pragma once
#include <iostream>

struct dank_vec4 {
	float x, y, z, w;

	dank_vec4();
	dank_vec4(const float& x, const float& y, const float& z, const float& w);

	float length();

	dank_vec4& add(const float& scalar);
	dank_vec4& subtract(const float& scalar);
	dank_vec4& multiply(const float& scalar);
	dank_vec4& divide(const float& scalar);

	dank_vec4& add(const dank_vec4& vector);
	dank_vec4& subtract(const dank_vec4& vector);
	dank_vec4& multiply(const dank_vec4& vector);
	dank_vec4& divide(const dank_vec4& vector);

	dank_vec4& operator+(const float& scalar);
	dank_vec4& operator-(const float& scalar);
	dank_vec4& operator*(const float& scalar);
	dank_vec4& operator/(const float& scalar);

	dank_vec4& operator+(const dank_vec4& vector);
	dank_vec4& operator-(const dank_vec4& vector);
	dank_vec4& operator*(const dank_vec4& vector);
	dank_vec4& operator/(const dank_vec4& vector);

	dank_vec4& operator+=(const float& scalar);
	dank_vec4& operator-=(const float& scalar);
	dank_vec4& operator*=(const float& scalar);
	dank_vec4& operator/=(const float& scalar);

	dank_vec4& operator+=(const dank_vec4& vector);
	dank_vec4& operator-=(const dank_vec4& vector);
	dank_vec4& operator*=(const dank_vec4& vector);
	dank_vec4& operator/=(const dank_vec4& vector);

	bool operator==(const dank_vec4& v);
	bool operator!=(const dank_vec4& v);

	friend std::ostream& operator<<(std::ostream& os, const dank_vec4& v);
};
