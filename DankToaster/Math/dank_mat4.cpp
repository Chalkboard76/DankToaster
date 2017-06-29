#include "dank_mat4.h"

dank_mat4::dank_mat4() {
	for (int i = 0; i < 16; i++) {
		elements[i] = 0;
	}
	elements[0 + 0 * 4] = 1;
	elements[1 + 1 * 4] = 1;
	elements[2 + 2 * 4] = 1;
	elements[3 + 3 * 4] = 1;
}
dank_mat4::dank_mat4(float e[16]) {
	for (int i = 0; i < 16; i++) {
		elements[i] = e[i];
	}
}
dank_mat4::dank_mat4(float diag) {
	for (int i = 0; i < 16; i++) {
		elements[i] = 0;
	}
	elements[0 + 0 * 4] = diag;
	elements[1 + 1 * 4] = diag;
	elements[2 + 2 * 4] = diag;
	elements[3 + 3 * 4] = diag;
}
dank_mat4& dank_mat4::add(float scalar) {
	for (int i = 0; i < 16; i++) {
		elements[i] += scalar;
	}
	return *this;
}
dank_mat4& dank_mat4::subtract(float scalar) {
	for (int i = 0; i < 16; i++) {
		elements[i] -= scalar;
	}
	return *this;
}
dank_mat4& dank_mat4::multiply(float scalar) {
	for (int i = 0; i < 16; i++) {
		elements[i] *= scalar;
	}
	return *this;
}
dank_mat4& dank_mat4::divide(float scalar) {
	for (int i = 0; i < 16; i++) {
		elements[i] /= scalar;
	}
	return *this;
}
dank_mat4& dank_mat4::add(const dank_mat4& matrix) {
	for (int i = 0; i < 16; i++) {
		elements[i] += matrix.elements[i];
	}
	return *this;
}
dank_mat4& dank_mat4::subtract(const dank_mat4& matrix) {
	for (int i = 0; i < 16; i++) {
		elements[i] -= matrix.elements[i];
	}
	return *this;
}
dank_mat4 dank_mat4::multiply(const dank_mat4& matrix) {
	dank_mat4 result;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			float sum = 0;
			for (int e = 0; e < 4; e++) {
				sum += elements[x + e * 4] * matrix.elements[e + y * 4];
			}
			result.elements[x + y * 4] = sum;
		}
	}
	return result;
}
dank_vec4 dank_mat4::multiply(const dank_vec4& vector) {
	dank_vec4 result;
	result.x = elements[0 + 0 * 4] * vector.x
		+ elements[0 + 1 * 4] * vector.y
		+ elements[0 + 2 * 4] * vector.z
		+ elements[0 + 3 * 4] * vector.w;
	result.y = elements[1 + 0 * 4] * vector.x
		+ elements[1 + 1 * 4] * vector.y
		+ elements[1 + 2 * 4] * vector.z
		+ elements[1 + 3 * 4] * vector.w;
	result.z = elements[2 + 0 * 4] * vector.x
		+ elements[2 + 1 * 4] * vector.y
		+ elements[2 + 2 * 4] * vector.z
		+ elements[2 + 3 * 4] * vector.w;
	result.w = elements[3 + 0 * 4] * vector.x
		+ elements[3 + 1 * 4] * vector.y
		+ elements[3 + 2 * 4] * vector.z
		+ elements[3 + 3 * 4] * vector.w;
	return result;
}
dank_mat4& dank_mat4::operator+(const float& scalar) {
	return add(scalar);
}
dank_mat4& dank_mat4::operator-(const float& scalar) {
	return subtract(scalar);
}
dank_mat4& dank_mat4::operator*(const float& scalar) {
	return multiply(scalar);
}
dank_mat4& dank_mat4::operator+(const dank_mat4& matrix) {
	return add(matrix);
}
dank_mat4& dank_mat4::operator-(const dank_mat4& matrix) {
	return subtract(matrix);
}
dank_mat4 dank_mat4::operator*(dank_mat4& matrix) {
	return multiply(matrix);
}
dank_vec4 dank_mat4::operator*(const dank_vec4& vector) {
	return multiply(vector);
}
dank_mat4 identity() {
	return dank_mat4();
}
dank_mat4 orthographic(float left, float right, float top, float bottom, float near, float far) {
	dank_mat4 result(1);

	result.elements[0 + 0 * 4] = 2 / (right - left);
	result.elements[1 + 1 * 4] = 2 / (top - bottom);
	result.elements[2 + 2 * 4] = -2 / (far - near);

	result.elements[0 + 3 * 4] = -(left + right) / (right - left);
	result.elements[1 + 3 * 4] = -(bottom + top) / (top - bottom);
	result.elements[2 + 3 * 4] = -(far + near) / (far - near);

	return result;
}
dank_mat4 perspective(float fieldOfView, float aspectRatio, float near, float far) {
	dank_mat4 result(1);

	float q = 1.0f / tan(toRadians(0.5f * fieldOfView));
	float a = q / aspectRatio;

	float b = (near + far) / (near - far);
	float c = (2 * near * far) / (near - far);

	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = b;
	result.elements[3 + 2 * 4] = -1;
	result.elements[2 + 3 * 4] = c;

	return result;
}
dank_mat4 scalingMatrix(const dank_vec3& diag) {
	dank_mat4 result;
	result.elements[0 + 0 * 4] = diag.x;
	result.elements[1 + 1 * 4] = diag.y;
	result.elements[2 + 2 * 4] = diag.z;
	result.elements[3 + 3 * 4] = 1;
	return result;
}
dank_mat4 translationMatrix(const dank_vec3& vector) {
	dank_mat4 result;
	result.elements[0 + 3 * 4] = vector.x;
	result.elements[1 + 3 * 4] = vector.y;
	result.elements[2 + 3 * 4] = vector.z;
	return result;
}
dank_mat4 rotationMatrix(float angleDegrees, dank_vec3& axis) {
	dank_mat4 result = identity();

	float radians = toRadians(angleDegrees);
	float s = sin(radians);
	float c = cos(radians);
	std::cout << c << std::endl;

	result.elements[0 + 0 * 4] = axis.x * axis.x * (1 - c) + c;
	result.elements[1 + 0 * 4] = axis.y * axis.x * (1 - c) + axis.z * s;
	result.elements[2 + 0 * 4] = axis.x * axis.z * (1 - c) - axis.y * s;

	result.elements[0 + 1 * 4] = axis.x * axis.y * (1 - c) - axis.z * s;
	result.elements[1 + 1 * 4] = axis.y * axis.y * (1 - c) + c;
	result.elements[2 + 1 * 4] = axis.y * axis.z * (1 - c) + axis.x * s;

	result.elements[0 + 2 * 4] = axis.x * axis.z * (1 - c) + axis.y * s;
	result.elements[1 + 2 * 4] = axis.y * axis.z * (1 - c) - axis.x * s;
	result.elements[2 + 2 * 4] = axis.z * axis.z * (1 - c) + c;

	return result;
}

std::ostream& operator<<(std::ostream& os, dank_mat4& matrix) {
	for (int i = 0; i < 4; i++) {
		os <<
			matrix.elements[0 + i] << " " << matrix.elements[4 + i] << " " <<
			matrix.elements[8 + i] << " " << matrix.elements[12 + i] << std::endl;
	}
	return os;
}
