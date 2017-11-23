#pragma once

#include "dank_vec4.h"
#include "dank_vec3.h"
#include "Math.h"

struct dank_mat4 {
	float elements[16];
	dank_mat4();
	dank_mat4(float e[16]);
	dank_mat4(float diag);

	dank_mat4& add(float scalar);
	dank_mat4& subtract(float scalar);
	dank_mat4& multiply(float scalar);
	dank_mat4& divide(float scalar);

	dank_mat4& add(const dank_mat4& matrix);
	dank_mat4& subtract(const dank_mat4& matrix);
	dank_mat4 multiply(const dank_mat4& matrix);
	dank_vec3 multiply(const dank_vec3& vector);
	dank_vec4 multiply(const dank_vec4& vector);

	dank_mat4& operator+(const float& scalar);
	dank_mat4& operator-(const float& scalar);
	dank_mat4& operator*(const float& scalar);

	dank_mat4& operator+(const dank_mat4& matrix);
	dank_mat4& operator-(const dank_mat4& matrix);
	dank_mat4 operator*(dank_mat4& matrix);
	dank_vec3 operator*(const dank_vec3& vector);
	dank_vec4 operator*(const dank_vec4& vector);

	friend std::ostream& operator<<(std::ostream& os, dank_mat4& matrix);

	friend dank_mat4 identity();
	friend dank_mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
	friend dank_mat4 perspective(float fieldOfView, float aspectRatio, float near, float far);
	friend dank_mat4 scalingMatrix(const dank_vec3& diag);
	friend dank_mat4 translationMatrix(const dank_vec3& vector);
	friend dank_mat4 rotationMatrix(float angleDegrees, dank_vec3& axis);
	friend dank_mat4 lookAt(dank_vec3& cameraPos, dank_vec3& targetPos, dank_vec3& worldUp);
	friend dank_mat4 lookAt(dank_vec3& position, dank_vec3& front, dank_vec3& right, dank_vec3& up);
};
