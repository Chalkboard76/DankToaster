#include "dank_vec4.h"
#include <math.h>

dank_vec4::dank_vec4() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
dank_vec4::dank_vec4(const float& x, const float& y, const float& z, const float& w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float dank_vec4::length() {
	return sqrt(x*x + y*y + z*z + w*w);
}

dank_vec4& dank_vec4::add(const float& scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	w += scalar;
	return *this;
}
dank_vec4& dank_vec4::subtract(const float& scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	w -= scalar;
	return *this;
}
dank_vec4& dank_vec4::multiply(const float& scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}
dank_vec4& dank_vec4::divide(const float& scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

dank_vec4& dank_vec4::add(const dank_vec4& vector) {
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;
	return *this;
}
dank_vec4& dank_vec4::subtract(const dank_vec4& vector) {
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;
	return *this;
}
dank_vec4& dank_vec4::multiply(const dank_vec4& vector) {
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	w *= vector.w;
	return *this;
}
dank_vec4& dank_vec4::divide(const dank_vec4& vector) {
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	w /= vector.w;
	return *this;
}

dank_vec4& dank_vec4::operator+(const float& scalar) {
	return add(scalar);
}
dank_vec4& dank_vec4::operator-(const float& scalar) {
	return subtract(scalar);
}
dank_vec4& dank_vec4::operator*(const float& scalar) {
	return multiply(scalar);
}
dank_vec4& dank_vec4::operator/(const float& scalar) {
	return divide(scalar);
}

dank_vec4& dank_vec4::operator+(const dank_vec4& vector) {
	return add(vector);
}
dank_vec4& dank_vec4::operator-(const dank_vec4& vector) {
	return subtract(vector);
}
dank_vec4& dank_vec4::operator*(const dank_vec4& vector) {
	return multiply(vector);
}
dank_vec4& dank_vec4::operator/(const dank_vec4& vector) {
	return divide(vector);
}

dank_vec4& dank_vec4::operator+=(const float& scalar) {
	return add(scalar);
}
dank_vec4& dank_vec4::operator-=(const float& scalar) {
	return subtract(scalar);
}
dank_vec4& dank_vec4::operator*=(const float& scalar) {
	return multiply(scalar);
}
dank_vec4& dank_vec4::operator/=(const float& scalar) {
	return divide(scalar);
}

dank_vec4& dank_vec4::operator+=(const dank_vec4& vector) {
	return add(vector);
}
dank_vec4& dank_vec4::operator-=(const dank_vec4& vector) {
	return subtract(vector);
}
dank_vec4& dank_vec4::operator*=(const dank_vec4& vector) {
	return multiply(vector);
}
dank_vec4& dank_vec4::operator/=(const dank_vec4& vector) {
	return divide(vector);
}

bool dank_vec4::operator==(const dank_vec4& v) {
	return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}
bool dank_vec4::operator!=(const dank_vec4& v) {
	return x != v.x || y != v.y || z != v.z || w != v.w;
}

std::ostream& operator<<(std::ostream& os, const dank_vec4& v) {
	os << "dank_vec4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return os;
}
