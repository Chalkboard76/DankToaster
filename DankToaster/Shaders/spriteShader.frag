#version 420 core

out vec4 FragColor;

in vec2 ourUV;
in float ourTexID;

uniform sampler2D our_textures[32];

void main()
{
	vec4 texColor;
	int tid = int(ourTexID);
	texColor = texture(our_textures[0], ourUV);
	FragColor = texColor;
}