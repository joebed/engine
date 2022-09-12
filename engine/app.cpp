#include "app.h"

App::App() {
	// Need to create window, then surface
	window = SDL_CreateWindow("Homedawg", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN);
	if (!window) {
		std::cout << "Window could not be created\n\
			SDL Error: " << SDL_GetError() << "\n";
		SDL_Quit();
		return;
	}

	surface = SDL_GetWindowSurface(window);
	if (!surface) {
		std::cout << "Window could not be created\n\
			SDL Error: " << SDL_GetError() << "\n";
		SDL_Quit();
		return;
	}
}

App::~App() {

}
