#pragma once

#include "Math\dank_vec3.h"
#include "Math\dank_mat4.h"

static const float PITCH = 0.0f;
static const float YAW = -90.0f;
static const float SPEED = 2.5f;
static const float SENSITIVITY = 0.1f;
static const float ZOOM = 45.0f;

enum camera_movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class dank_camera {
private:
	float _pitch, _yaw;
	float _speed;
	float _mouse_sensitivity;
	float _zoom;
	dank_vec3 _position;
	dank_vec3 _up;
	dank_vec3 _right;
	dank_vec3 _front;
	dank_vec3 _world_up;
public:
	dank_camera(dank_vec3 position, dank_vec3 up);
	~dank_camera();
	void update_camera_vectors();
	dank_mat4 get_view_matrix();
};