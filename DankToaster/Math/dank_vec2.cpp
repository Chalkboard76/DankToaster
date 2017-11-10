#include "dank_vec2.h"
#include <math.h>

dank_vec2::dank_vec2() {
	x = 0.0f;
	y = 0.0f;
}
dank_vec2::dank_vec2(const float& x, const float& y) {
	this->x = x;
	this->y = y;
}

float dank_vec2::length() {
	return sqrt(x*x + y*y);
}

dank_vec2& dank_vec2::add(const float& scalar) {
	x += scalar;
	y += scalar;
	return *this;
}
dank_vec2& dank_vec2::subtract(const float& scalar) {
	x -= scalar;
	y -= scalar;
	return *this;
}
dank_vec2& dank_vec2::multiply(const float& scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}
dank_vec2& dank_vec2::divide(const float& scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

dank_vec2& dank_vec2::add(const dank_vec2& vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}
dank_vec2& dank_vec2::subtract(const dank_vec2& vector) {
	x -= vector.x;
	y -= vector.y;
	return *this;
}
dank_vec2& dank_vec2::multiply(const dank_vec2& vector) {
	x *= vector.x;
	y *= vector.y;
	return *this;
}
dank_vec2& dank_vec2::divide(const dank_vec2& vector) {
	x /= vector.x;
	y /= vector.y;
	return *this;
}

dank_vec2& dank_vec2::operator+(const float& scalar) {
	return add(scalar);
}
dank_vec2& dank_vec2::operator-(const float& scalar) {
	return subtract(scalar);
}
dank_vec2& dank_vec2::operator*(const float& scalar) {
	return multiply(scalar);
}
dank_vec2& dank_vec2::operator/(const float& scalar) {
	return divide(scalar);
}

dank_vec2& dank_vec2::operator+(const dank_vec2& vector) {
	return add(vector);
}
dank_vec2& dank_vec2::operator-(const dank_vec2& vector) {
	return subtract(vector);
}
dank_vec2& dank_vec2::operator*(const dank_vec2& vector) {
	return multiply(vector);
}
dank_vec2& dank_vec2::operator/(const dank_vec2& vector) {
	return divide(vector);
}

dank_vec2& dank_vec2::operator+=(const float& scalar) {
	return add(scalar);
}
dank_vec2& dank_vec2::operator-=(const float& scalar) {
	return subtract(scalar);
}
dank_vec2& dank_vec2::operator*=(const float& scalar) {
	return multiply(scalar);
}
dank_vec2& dank_vec2::operator/=(const float& scalar) {
	return divide(scalar);
}

dank_vec2& dank_vec2::operator+=(const dank_vec2& vector) {
	return add(vector);
}
dank_vec2& dank_vec2::operator-=(const dank_vec2& vector) {
	return subtract(vector);
}
dank_vec2& dank_vec2::operator*=(const dank_vec2& vector) {
	return multiply(vector);
}
dank_vec2& dank_vec2::operator/=(const dank_vec2& vector) {
	return divide(vector);
}

dank_vec2& normalize(const dank_vec2& vector) {
	float magnitude = (vector.x * vector.x) + (vector.y * vector.y);
	return dank_vec2(vector.x / magnitude, vector.y / magnitude);
}

bool dank_vec2::operator==(const dank_vec2& v) {
	return (x == v.x) && (y == v.y);
}
bool dank_vec2::operator!=(const dank_vec2& v) {
	return x != v.x || y != v.y;
}

std::ostream& operator<<(std::ostream& os, const dank_vec2& v) {
	os << "dank_vec2(" << v.x << ", " << v.y << ")";
	return os;
}
