#pragma once
#include <iostream>

struct dank_vec3 {
	float x, y, z;

	dank_vec3();
	dank_vec3(const float& x, const float& y, const float& z);

	float length();

	dank_vec3 add(const dank_vec3& v1, const float& scalar);
	dank_vec3 subtract(const dank_vec3& v1, const float& scalar);
	dank_vec3 multiply(const dank_vec3& v1, const float& scalar);
	dank_vec3 divide(const dank_vec3& v1, const float& scalar);

	dank_vec3 add(const dank_vec3& v1, const dank_vec3& v2);
	dank_vec3 subtract(const dank_vec3& v1, const dank_vec3& v2);
	dank_vec3 multiply(const dank_vec3& v1, const dank_vec3& v2);
	dank_vec3 divide(const dank_vec3& v1, const dank_vec3& v2);

	void add(const float& scalar);
	void subtract(const float& scalar);
	void multiply(const float& scalar);
	void divide(const float& scalar);

	void add(const dank_vec3& vector);
	void subtract(const dank_vec3& vector);
	void multiply(const dank_vec3& vector);
	void divide(const dank_vec3& vector);

	dank_vec3 operator+(const float& scalar);
	dank_vec3 operator-(const float& scalar);
	dank_vec3 operator*(const float& scalar);
	dank_vec3 operator/(const float& scalar);

	dank_vec3 operator+(const dank_vec3& vector);
	dank_vec3 operator-(const dank_vec3& vector);
	dank_vec3 operator*(const dank_vec3& vector);
	dank_vec3 operator/(const dank_vec3& vector);

	dank_vec3& operator+=(const float& scalar);
	dank_vec3& operator-=(const float& scalar);
	dank_vec3& operator*=(const float& scalar);
	dank_vec3& operator/=(const float& scalar);

	dank_vec3& operator+=(const dank_vec3& vector);
	dank_vec3& operator-=(const dank_vec3& vector);
	dank_vec3& operator*=(const dank_vec3& vector);
	dank_vec3& operator/=(const dank_vec3& vector);

	friend dank_vec3 normalize(const dank_vec3& vector);
	friend dank_vec3 cross(const dank_vec3& a, const dank_vec3& b);

	bool operator==(const dank_vec3& v);
	bool operator!=(const dank_vec3& v);

	friend std::ostream& operator<<(std::ostream& os, const dank_vec3& v);
};
