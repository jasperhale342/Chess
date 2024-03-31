#include <promote_pond_modal.h>
namespace chess {
	bool PromtePondModal::init(PieceColor piece_color) {
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



		if (m_renderer == NULL) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		

		// white pieces
		SDL_RenderClear(m_renderer);
		if (piece_color == WHITE) {
			loadAsset("assets/QueenWhite.bmp", QUEEN, piece_color, 0, 0);
			loadAsset("assets/RookWhite.bmp", ROOK, piece_color, 0, 100);
			loadAsset("assets/BishopWhite.bmp", BISHOP, piece_color, 100, 0);
			loadAsset("assets/KnightWhite.bmp", KNIGHT, piece_color, 100, 100);
		}
		else {
			loadAsset("assets/kingBlack.bmp", QUEEN, piece_color, 0, 0);
			loadAsset("assets/queenBlack.bmp", ROOK, piece_color, 0, 100);
			loadAsset("assets/bishopBlack.bmp", BISHOP, piece_color, 100, 0);
			loadAsset("assets/knightBlack.bmp", KNIGHT, piece_color, 100, 100);
	
		}
		
		SDL_SetRenderTarget(m_renderer, NULL);


		return true;
	}
	void PromtePondModal::loadAsset(const char* path, const PieceType pieceType, const PieceColor pieceColor, const int x, const int y ) {
		SDL_Surface* asset = nullptr;
		SDL_Texture* asset_texture = nullptr;
		asset = SDL_LoadBMP(path);
		asset_texture = SDL_CreateTextureFromSurface(m_renderer, asset);
		SDL_Rect pos = { x,y, 100, 100 };
		SDL_RenderCopy(m_renderer, asset_texture, NULL, &pos);
		SDL_FreeSurface(asset);
	}
	


}