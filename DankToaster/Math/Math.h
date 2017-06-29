#pragma once

#include "dank_vec2.h"
#include "dank_vec3.h"
#include "dank_vec4.h"
#include "dank_mat4.h"

# define M_PI 3.14159265358979323846f

float dotProduct(const dank_vec2& vec1, const dank_vec2& dank_vec2);
float dotProduct(const dank_vec3& vec1, const dank_vec3& dank_vec2);
float dotProduct(const dank_vec4& vec1, const dank_vec4& dank_vec2);

dank_vec3 crossProduct(const dank_vec3& vec1, const dank_vec3& dank_vec2);

float toRadians(float degree);
