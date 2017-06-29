#include "dank_shader.h"
#include "Utils\file_utils.h"

dank_shader::dank_shader() {
}

dank_shader::dank_shader(const char* vert, const char* frag) {
	std::string vertAsString = fileToString(vert);
	const char* vertAsStringP = vertAsString.c_str();
	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertID, 1, &vertAsStringP, NULL);
	glCompileShader(vertID);
	int success;
	char infoLog[512];
	glGetShaderiv(vertID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertID, 512, NULL, infoLog);
		std::cout << "Vertex Shader Failed to compile.\n" << infoLog << std::endl;
	}

	std::string fragAsString = fileToString(frag);
	const char* fragAsStringP = fragAsString.c_str();
	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragID, 1, &fragAsStringP, NULL);
	glCompileShader(fragID);
	glGetShaderiv(fragID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragID, 512, NULL, infoLog);
		std::cout << "Fragment Shader Failed to compile.\n" << infoLog << std::endl;
	}

	_programID = glCreateProgram();
	glAttachShader(_programID, vertID);
	glAttachShader(_programID, fragID);

	glLinkProgram(_programID);
	glValidateProgram(_programID);
	glGetProgramiv(_programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_programID, 512, NULL, infoLog);
		std::cout << "Shader failed to link.\n" << infoLog << std::endl;
	}
	glDeleteShader(vertID);
	glDeleteShader(fragID);
}
dank_shader::~dank_shader() {
	glDeleteProgram(_programID);
}
void dank_shader::enable() {
	glUseProgram(_programID);
}
void dank_shader::disable() {
	glUseProgram(0);
}
void dank_shader::setUniformMat4(char* name, dank_mat4 matrix) {
	int loc = glGetUniformLocation(_programID, name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, matrix.elements);
}
void dank_shader::setUniform1fv(char* name, float* data, int count) {
	int loc = glGetUniformLocation(_programID, name);
	glUniform1fv(loc, count, data);
}
void dank_shader::setUniform1v(char* name, int* data, int count) {
	glUniform1iv(glGetUniformLocation(_programID, name), count, data);
}
