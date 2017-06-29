#include "file_utils.h"

std::string fileToString(const char* filepath) {
	std::ifstream t(filepath);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	return str;
}
