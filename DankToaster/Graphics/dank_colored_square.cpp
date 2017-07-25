#include "dank_colored_square.h"

dank_colored_square::dank_colored_square() {

}
dank_colored_square::dank_colored_square(float xcoord, float ycoord, float width, float height, dank_vec4 color) {
	vertices[0].position = dank_vec3(xcoord, ycoord, 0);
	vertices[0].color = color;

	vertices[1].position = dank_vec3(xcoord + width, ycoord, 0);
	vertices[1].color = color;

	vertices[2].position = dank_vec3(xcoord + width, ycoord + height, 0);
	vertices[2].color = color;

	vertices[3].position = dank_vec3(xcoord, ycoord + height, 0);
	vertices[3].color = color;
}
dank_colored_square::~dank_colored_square() {

}