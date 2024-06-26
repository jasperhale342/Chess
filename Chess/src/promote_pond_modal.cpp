#include <promote_pond_modal.h>
#include <iostream>
namespace chess {
	bool PromtePondModal::init() {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
			return false;
		}
		m_window = SDL_CreateWindow("PromotePondModal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);


		if (m_window == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		SDL_SetWindowBordered(m_window, SDL_FALSE);

		if (m_renderer == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		

		// white pieces

		SDL_RenderClear(m_renderer);
		loadAsset("assets/QueenWhite.bmp", QUEEN, 0, 0);
		loadAsset("assets/RookWhite.bmp", ROOK, 0, 100);
		loadAsset("assets/BishopWhite.bmp", BISHOP, 100, 0);
		loadAsset("assets/KnightWhite.bmp", KNIGHT, 100, 100);

		SDL_HideWindow(m_window);

		return true;
	}
	void PromtePondModal::loadAsset(const char* path, const PieceType pieceType, const int x, const int y ) {
		SDL_Surface* asset = nullptr;
		SDL_Texture* asset_texture = nullptr;
		asset = SDL_LoadBMP(path);
		asset_texture = SDL_CreateTextureFromSurface(m_renderer, asset);

		Coor pos = { x, y };
		m_piece_positions.emplace(pos, pieceType);
		m_piece_textures.emplace(pieceType, asset_texture);
		SDL_FreeSurface(asset);
		SDL_Rect pos2 = { x,y, 100, 100 };
		SDL_RenderCopy(m_renderer, asset_texture, NULL, &pos2);
	}

	void PromtePondModal::display(int x, int y) {
		SDL_SetWindowPosition(m_window, x, y);
		SDL_ShowWindow(m_window);
		SDL_RenderPresent(m_renderer);
		//SDL_SetWindowInputFocus(m_window);
		SDL_SetWindowGrab(m_window, SDL_TRUE);

	}
	void PromtePondModal::close_display() {
		SDL_HideWindow(m_window);
	}
	void PromtePondModal::quit() {

		SDL_DestroyRenderer(m_renderer);
		for (auto it = m_piece_textures.begin(); it != m_piece_textures.end(); ++it) {
			SDL_DestroyTexture((it->second));
		}
		SDL_DestroyWindow(m_window);
	}

	PieceType  PromtePondModal::select_piece(int x, int y) {
		std::cout << "from Pond Modal: Selecting piece at, " << x << ", " << y << std::endl;
		PieceType piece = m_piece_positions.at({ x, y });
		return piece;

	}
	


}