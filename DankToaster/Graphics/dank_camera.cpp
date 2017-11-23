#include "dank_camera.h"

dank_camera::dank_camera(dank_vec3 position, dank_vec3 up): 
	_pitch(PITCH), _yaw(YAW), _speed(SPEED), _mouse_sensitivity(SENSITIVITY), _zoom(ZOOM), 
	_position(position), _world_up(up)
{
	update_camera_vectors();
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

dank_mat4 dank_camera::get_view_matrix() {
	return lookAt(_position, _front, _right, _up);
}