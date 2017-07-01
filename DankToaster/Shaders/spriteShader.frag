#version 420 core

out vec4 frag_color;

in vec2 our_UV;
in float our_tex_unit;

uniform sampler2D our_textures[32];

void main()
{
	vec4 tex_color;
	int tid = int(our_tex_unit);
	tex_color = texture(our_textures[0], our_UV);
	frag_color = tex_color;
}