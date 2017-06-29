#version 420 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

out vec4 ourColor;

uniform mat4 model = mat4(1.0f);
uniform mat4 view = mat4(1.0f);
uniform mat4 projection = mat4(1.0f);

void main()
{
	gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1);
	ourColor = color;
}

