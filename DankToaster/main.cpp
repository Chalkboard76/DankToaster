#include "Graphics\dank_window.h"

int main() {
	dank_window window(1024, 576, "Testtttt");
	glClearColor(1, 0, 1, 1);
	while (window.open()) {
		window.clear();
		window.update();
	}
	return 0;
}