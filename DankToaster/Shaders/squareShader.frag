#version 420 core

out vec4 frag_color;

in vec4 our_color;

void main()
{
	frag_color = our_color;
}