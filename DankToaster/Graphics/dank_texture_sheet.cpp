#include "Graphics\dank_texture_sheet.h"
#include <GL\glew.h>
#include <string>

#define STB_IMAGE_IMPLEMENTATION    
#include "Utils/stb_image.h"

dank_texture_sheet::dank_texture_sheet() {
}
dank_texture_sheet::dank_texture_sheet(const std::string& path) {
	int width, height, numChannels;
	glGenTextures(1, &tex_ID);
	glBindTexture(GL_TEXTURE_2D, tex_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &numChannels, 0);
	if (imageData) {
		if (numChannels == 3) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		printf("Texture did not load properly.\n");
	}
	stbi_image_free(imageData);
}

dank_texture_sheet::~dank_texture_sheet() {
}
