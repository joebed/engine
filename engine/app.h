#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class InitException : std::exception {
	InitException(char* stage) {
		std::cerr << "Failed at creating the " << stage << ". Exiting...";
	}
};

class App {
public:
	App();
	~App();

private:
	SDL_Window* window;
	SDL_Surface* surface;
};

