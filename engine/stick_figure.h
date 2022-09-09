#pragma once

#include <SDL.h>
#include "spritesheet.h"

enum class Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class StickFigure {
public:
	StickFigure();
	~StickFigure() = default;

	void update(double delta_time);
	void draw(SDL_Surface* window_surface);
	void handle_events(SDL_Event const& event);
private:
	SDL_Rect m_position;
	Direction m_direction;
	Spritesheet m_spritesheet;

	double m_x;
	double m_y;
};