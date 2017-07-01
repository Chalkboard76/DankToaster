#version 420 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 UV;
layout (location = 2) in float tex_unit;

out vec2 our_UV;
out float our_tex_unit;

uniform mat4 model = mat4(1.0f);
uniform mat4 view = mat4(1.0f);
uniform mat4 projection = mat4(1.0f);

void main()
{
	gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1);
	our_UV = UV;
	our_tex_unit = tex_unit;
}

