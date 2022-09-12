#pragma once

#include <SDL.h>
//#include "utilities.h"

class Spritesheet {
public:
	Spritesheet(char const* path, int row, int col);
	Spritesheet();
	~Spritesheet();

	void select_sprite(int x, int y);
	void draw_selected_sprite(SDL_Surface* window_surface, SDL_Rect* position);

private:
	SDL_Rect m_clip;
	SDL_Surface* m_spritesheet_image;
};