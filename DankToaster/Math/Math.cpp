#include "Math.h"

float dotProduct(const dank_vec2& vec1, const dank_vec2& dank_vec2) {
	return (vec1.x * dank_vec2.x + vec1.y + dank_vec2.y);
}
float dotProduct(const dank_vec3& vec1, const dank_vec3& dank_vec2) {
	return (vec1.x * dank_vec2.x) + (vec1.y * dank_vec2.y)
		+ (vec1.z * dank_vec2.z);
}
float dotProduct(const dank_vec4& vec1, const dank_vec4& dank_vec2) {
	return (vec1.x * dank_vec2.x) + (vec1.y * dank_vec2.y)
		+ (vec1.z * dank_vec2.z) + (vec1.w * dank_vec2.w);
}
dank_vec3 crossProduct(const dank_vec3& vec1, const dank_vec3& dank_vec2) {
	dank_vec3 result(vec1.y * dank_vec2.z - vec1.z * dank_vec2.y,
		vec1.z * dank_vec2.x - vec1.x * dank_vec2.z,
		vec1.x * dank_vec2.y - vec1.y * dank_vec2.x);
	return result;
}

float toRadians(float degree) {
	return degree * (M_PI / 180.0f);
}
