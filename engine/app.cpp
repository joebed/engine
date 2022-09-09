#include "app.h"

App::App() {

	m_window = SDL_CreateWindow("SDL2 Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		680, 480,
		0);

	if (!m_window) {
		std::cout << "Failed to create window\n\
					SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	m_window_surface = SDL_GetWindowSurface(m_window);

	if (!m_window_surface) {
		std::cout << "Failed to get window's surface\n\
					SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}
}

App::~App() {
	SDL_FreeSurface(m_window_surface);
	SDL_DestroyWindow(m_window);
} 

void App::loop() {

	bool keep_window_open = true;
	while (keep_window_open) {
		while (SDL_PollEvent(&m_window_event) > 0) {
			m_stick_figure.handle_events(m_window_event);
			switch (m_window_event.type) {
			case SDL_QUIT:
				keep_window_open = false;
				break;
			}
		}
		update(1.0/60.0);
		draw();
	}
}

void App::update(double delta_time) {
	m_stick_figure.update(delta_time);
}

void App::draw() {
	SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
	m_stick_figure.draw(m_window_surface);
	SDL_UpdateWindowSurface(m_window);
}

SDL_Surface* load_surface(char const* path) {
	SDL_Surface* image_surface = SDL_LoadBMP(path);

	if (!image_surface) return 0;
	return image_surface;
}
