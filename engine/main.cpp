#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "app.h"

int main(int argc, char** argv) {
	std::cout << "Initializing SDL and IMG...\n";
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL did not initialize\n\
					SDL Error: " << SDL_GetError() << "\n";
		return 1;
	}
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "IMG did not initialize\n\
					IMG Error: " << IMG_GetError() << "\n";
		return 1;
	}

	std::cout << "Initializing went swimmingly, you could say\n";


	return 0;
}