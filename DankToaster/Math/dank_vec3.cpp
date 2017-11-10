#include "dank_vec3.h"
#include <math.h>

dank_vec3::dank_vec3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
dank_vec3::dank_vec3(const float& x, const float& y, const float& z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float dank_vec3::length() {
	return sqrt(x*x + y*y + z*z);
}

dank_vec3& dank_vec3::add(const float& scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	return *this;
}
dank_vec3& dank_vec3::subtract(const float& scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	return *this;
}
dank_vec3& dank_vec3::multiply(const float& scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
dank_vec3& dank_vec3::divide(const float& scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

dank_vec3& dank_vec3::add(const dank_vec3& vector) {
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}
dank_vec3& dank_vec3::subtract(const dank_vec3& vector) {
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}
dank_vec3& dank_vec3::multiply(const dank_vec3& vector) {
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	return *this;
}
dank_vec3& dank_vec3::divide(const dank_vec3& vector) {
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	return *this;
}

dank_vec3& dank_vec3::operator+(const float& scalar) {
	return add(scalar);
}
dank_vec3& dank_vec3::operator-(const float& scalar) {
	return subtract(scalar);
}
dank_vec3& dank_vec3::operator*(const float& scalar) {
	return multiply(scalar);
}
dank_vec3& dank_vec3::operator/(const float& scalar) {
	return divide(scalar);
}

dank_vec3& dank_vec3::operator+(const dank_vec3& vector) {
	return add(vector);
}
dank_vec3& dank_vec3::operator-(const dank_vec3& vector) {
	return subtract(vector);
}
dank_vec3& dank_vec3::operator*(const dank_vec3& vector) {
	return multiply(vector);
}
dank_vec3& dank_vec3::operator/(const dank_vec3& vector) {
	return divide(vector);
}

dank_vec3& dank_vec3::operator+=(const float& scalar) {
	return add(scalar);
}
dank_vec3& dank_vec3::operator-=(const float& scalar) {
	return subtract(scalar);
}
dank_vec3& dank_vec3::operator*=(const float& scalar) {
	return multiply(scalar);
}
dank_vec3& dank_vec3::operator/=(const float& scalar) {
	return divide(scalar);
}

dank_vec3& dank_vec3::operator+=(const dank_vec3& vector) {
	return add(vector);
}
dank_vec3& dank_vec3::operator-=(const dank_vec3& vector) {
	return subtract(vector);
}
dank_vec3& dank_vec3::operator*=(const dank_vec3& vector) {
	return multiply(vector);
}
dank_vec3& dank_vec3::operator/=(const dank_vec3& vector) {
	return divide(vector);
}

dank_vec3& normalize(const dank_vec3& vector) {
	float magnitude = (vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z);
	return dank_vec3(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude);
}

dank_vec3& cross(const dank_vec3& a, const dank_vec3& b) {
	return dank_vec3(	a.y*b.z - a.z*b.y,
						a.z*b.x - a.x*b.z,
						a.x*b.y - a.y*b.x);
}

bool dank_vec3::operator==(const dank_vec3& v) {
	return (x == v.x) && (y == v.y) && (z == v.z);
}
bool dank_vec3::operator!=(const dank_vec3& v) {
	return x != v.x || y != v.y || z != v.z;
}

std::ostream& operator<<(std::ostream& os, const dank_vec3& v) {
	os << "dank_vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}
