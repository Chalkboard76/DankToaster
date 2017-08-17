#include "Graphics\dank_texture_sheet.h"
#include <GL\glew.h>
#include <string>

#define STB_IMAGE_IMPLEMENTATION    
#include "Utils/stb_image.h"

dank_texture_sheet::dank_texture_sheet() {
}
dank_texture_sheet::dank_texture_sheet(const std::string& path, float sheet_width, float sheet_height, float tex_size) {
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

	for (float i = 0; i < sheet_height; i += tex_size) {
		for (float j = 0; j < sheet_width; j += tex_size) {
			dank_texture* tex = new dank_texture(dank_vec2(i, j), tex_size, tex_size);
			tex->tex_ID = this->tex_ID;
			textures.push_back(tex);
		}
	}
}

dank_texture_sheet::~dank_texture_sheet() {
	for (int i = 0; i < textures.size(); i++) {
		delete textures[i];
	}
}
