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

dank_vec3 dank_vec3::add(const dank_vec3& v1, const float& scalar) {
	return dank_vec3(v1.x + scalar, v1.y + scalar, v1.z + scalar);
}
dank_vec3 dank_vec3::subtract(const dank_vec3& v1, const float& scalar) {
	return dank_vec3(v1.x - scalar, v1.y - scalar, v1.z - scalar);
}
dank_vec3 dank_vec3::multiply(const dank_vec3& v1, const float& scalar) {
	return dank_vec3(v1.x * scalar, v1.y * scalar, v1.z * scalar);
}
dank_vec3 dank_vec3::divide(const dank_vec3& v1, const float& scalar) {
	return dank_vec3(v1.x / scalar, v1.y / scalar, v1.z / scalar);
}

dank_vec3 dank_vec3::add(const dank_vec3& v1, const dank_vec3& v2) {
	return dank_vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
dank_vec3 dank_vec3::subtract(const dank_vec3& v1, const dank_vec3& v2) {
	return dank_vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
dank_vec3 dank_vec3::multiply(const dank_vec3& v1, const dank_vec3& v2) {
	return dank_vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
dank_vec3 dank_vec3::divide(const dank_vec3& v1, const dank_vec3& v2) {
	return dank_vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

void dank_vec3::add(const float& scalar) {
	this->x += scalar;
	this->y += scalar;
	this->z += scalar;
}
void dank_vec3::subtract(const float& scalar) {
	this->x -= scalar;
	this->y -= scalar;
	this->z -= scalar;
}
void dank_vec3::multiply(const float& scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}
void dank_vec3::divide(const float& scalar) {
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
}

void dank_vec3::add(const dank_vec3& vector) {
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
}
void dank_vec3::subtract(const dank_vec3& vector) {
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;
}
void dank_vec3::multiply(const dank_vec3& vector) {
	this->x *= vector.x;
	this->y *= vector.y;
	this->z *= vector.z;
}
void dank_vec3::divide(const dank_vec3& vector) {
	this->x /= vector.x;
	this->y /= vector.y;
	this->z /= vector.z;
}

dank_vec3 dank_vec3::operator+(const float& scalar) {
	return add(*this, scalar);
}
dank_vec3 dank_vec3::operator-(const float& scalar) {
	return subtract(*this, scalar);
}
dank_vec3 dank_vec3::operator*(const float& scalar) {
	return multiply(*this, scalar);
}
dank_vec3 dank_vec3::operator/(const float& scalar) {
	return divide(*this, scalar);
}

dank_vec3 dank_vec3::operator+(const dank_vec3& vector) {
	return add(*this, vector);
}
dank_vec3 dank_vec3::operator-(const dank_vec3& vector) {
	return subtract(*this, vector);
}
dank_vec3 dank_vec3::operator*(const dank_vec3& vector) {
	return multiply(*this, vector);
}
dank_vec3 dank_vec3::operator/(const dank_vec3& vector) {
	return divide(*this, vector);
}

dank_vec3& dank_vec3::operator+=(const float& scalar) {
	this->add(scalar);
	return *this;
}
dank_vec3& dank_vec3::operator-=(const float& scalar) {
	this->subtract(scalar);
	return *this;
}
dank_vec3& dank_vec3::operator*=(const float& scalar) {
	this->multiply(scalar);
	return *this;
}
dank_vec3& dank_vec3::operator/=(const float& scalar) {
	this->divide(scalar);
	return *this;
}

dank_vec3& dank_vec3::operator+=(const dank_vec3& vector) {
	this->add(vector);
	return *this;
}
dank_vec3& dank_vec3::operator-=(const dank_vec3& vector) {
	this->subtract(vector);
	return *this;
}
dank_vec3& dank_vec3::operator*=(const dank_vec3& vector) {
	this->multiply(vector);
	return *this;
}
dank_vec3& dank_vec3::operator/=(const dank_vec3& vector) {
	this->divide(vector);
	return *this;
}

dank_vec3 normalize(const dank_vec3& vector) {
	float magnitude = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	return dank_vec3(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude);
}

dank_vec3 cross(const dank_vec3& a, const dank_vec3& b) {
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
