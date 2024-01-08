#include <iostream>
#include "screen.h"
#undef main
using namespace chess;
int main() {
	Screen screen;

	if (!screen.init()) {
		std::cout << "error initializing SDL" << std::endl;
	}
	screen.close();
	return 0;
}
