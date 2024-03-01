#include "Screen.h"
#include <fstream>

namespace chess {
	Screen::Screen() : m_window(NULL),
		m_renderer(NULL),
		m_piece_textures()
		 {
		
	
	}


	bool Screen::init() {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
			return false;
		}
		m_window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);


		if (m_window == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		

		if (m_renderer == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		//if (m_piece_textures == NULL) {
		//	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create textures: %s", SDL_GetError());
		//	SDL_DestroyRenderer(m_renderer);
		//	SDL_DestroyWindow(m_window);
		//	SDL_Quit();
		//	return false;

		//}

		return true;
	}

	
	void Screen::clear() {
		
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);

	}
	bool Screen::processEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.text.type == SDL_QUIT) {
				return false;
			}

		}
		return true;
	}
	void Screen::close() {
		
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(*m_textures);
		SDL_DestroyWindow(m_window);

	}
}