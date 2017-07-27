#version 420 core

out vec4 frag_color;

in vec2 our_UV;
in float our_tex_unit;

uniform sampler2D our_textures[32];

void main()
{
	int tid = int(our_tex_unit);
	frag_color = texture(our_textures[tid], our_UV);
}