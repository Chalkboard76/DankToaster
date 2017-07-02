#pragma once

#include <unordered_map>
#include <GL\glew.h>
#include "dank_character.h"

struct dank_character_set {
	std::unordered_map<GLchar, dank_character> characters;
};