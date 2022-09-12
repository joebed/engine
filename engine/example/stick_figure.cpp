#include "stick_figure.h"

StickFigure::StickFigure() {
	m_direction = Direction::NONE;

	m_position.x = 0;
	m_position.y = 0;
	m_position.w = 22;
	m_position.h = 43;

	m_x = 0.0;
	m_y = 0.0;
	m_spritesheet.select_sprite(1, 1);
}

void StickFigure::update(double delta_time) {
	switch (m_direction) {
	case Direction::NONE:
		m_x += 0.0;
		m_y += 0.0;
		m_spritesheet.select_sprite(1, 1);
		break;
	case Direction::UP:
		m_y = m_y - (5.0 * delta_time);
		m_spritesheet.select_sprite(0, 0);
		break;
	case Direction::DOWN:
		m_y = m_y + (5.0 * delta_time);
		m_spritesheet.select_sprite(1, 1);
		break;
	case Direction::LEFT:
		m_x = m_x - (5.0 * delta_time);
		m_spritesheet.select_sprite(1, 0);
		break;
	case Direction::RIGHT:
		m_x = m_x + (5.0 * delta_time);
		m_spritesheet.select_sprite(0, 1);
		break;
	}

	m_position.x = int(m_x);
	m_position.y = int(m_y);
}

void StickFigure::draw(SDL_Surface* window_surface) {
	m_spritesheet.draw_selected_sprite(window_surface, &m_position);
}

void StickFigure::handle_events(SDL_Event const& event) {
	switch (event.type) {
	case SDL_KEYDOWN:
		Uint8 const* keys = SDL_GetKeyboardState(nullptr);
		 
		if (keys[SDL_SCANCODE_W] == 1)
			m_direction = Direction::UP;
		else if (keys[SDL_SCANCODE_S] == 1)
			m_direction = Direction::DOWN;
		else if (keys[SDL_SCANCODE_A] == 1)
			m_direction = Direction::LEFT;
		else if (keys[SDL_SCANCODE_D] == 1)
			m_direction = Direction::RIGHT;
		else
			m_direction = Direction::NONE;
		break;
	}
}
