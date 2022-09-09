#include "spritesheet.h"
#include <iostream>

Spritesheet::Spritesheet(char const* path, int row, int col) {
	m_spritesheet_image = SDL_LoadBMP(path);

	m_clip.w = m_spritesheet_image->w / col;
	m_clip.h = m_spritesheet_image->h / row;
}

Spritesheet::Spritesheet() {
	m_spritesheet_image = SDL_LoadBMP("sticksheet.bmp");
	m_clip.w = m_spritesheet_image->w / 2;
	m_clip.h = m_spritesheet_image->h / 2;
}
Spritesheet::~Spritesheet(){
	SDL_FreeSurface(m_spritesheet_image);
}

void Spritesheet::select_sprite(int x, int y){
	m_clip.x = x * m_clip.w;
	m_clip.y = y * m_clip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Surface* window_surface, SDL_Rect* position){
	SDL_BlitSurface(m_spritesheet_image, &m_clip, window_surface, position);
}