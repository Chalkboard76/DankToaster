#include "dank_camera.h"

dank_camera::dank_camera(dank_vec3 position, dank_vec3 up): 
	_pitch(PITCH), _yaw(YAW), _speed(SPEED), _mouse_sensitivity(SENSITIVITY), _zoom(ZOOM), 
	_position(position), _world_up(up)
{
	update_camera_vectors();
}

dank_camera::~dank_camera() {
}

void dank_camera::update_camera_vectors() {
	dank_vec3 f;
	f.x = cos(_pitch) * cos(_yaw);
	f.y = sin(_pitch);
	f.z = cos(_pitch) * sin(_yaw);

	_front = normalize(f);
	_right = normalize(cross(_front, _world_up));
	_up = normalize(cross(_front, _right));
}

void dank_camera::process_keyboard_input(camera_movement dir) {
	float _relative_speed = _speed * deltatime;
	std::cout << deltatime << std::endl;
	if (dir == FORWARD) {
		_position -= _front * _relative_speed ;
	}
	else if (dir == BACKWARD) {
		_position += _front * _relative_speed;
	}
	else if (dir == LEFT) {
		_position += _right * _relative_speed;
	}
	else if (dir == RIGHT) {
		_position -= _right * _relative_speed;
	}
}

void dank_camera::process_mouse_movement(float xoffset, float yoffset) {
	xoffset *= _mouse_sensitivity;
	yoffset *= _mouse_sensitivity;

	_yaw += xoffset;
	_pitch += yoffset;

	if (_pitch > 89.0f) {
		_pitch = 89.0f;
	}
	if (_pitch < -89.0f) {
		_pitch = -89.0f;
	}

	update_camera_vectors();
}

void dank_camera::process_mouse_scroll(float yoffset) {
	if (_zoom >= 1.0f && _zoom <= 45.0f)
		_zoom -= yoffset;
	if (_zoom <= 1.0f)
		_zoom = 1.0f;
	if (_zoom >= 45.0f)
		_zoom = 45.0f;
}

dank_mat4 dank_camera::get_view_matrix() {
	return lookAt(_position, _front, _right, _up);
}