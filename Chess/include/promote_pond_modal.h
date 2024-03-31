#pragma once
#include <SDL.h>
#include <unordered_map>
#include <custom_hash_piece.h>
namespace chess {
	class PromtePondModal {
	public: 
		const static int SCREEN_WIDTH = 200;
		const static int SCREEN_HEIGHT = 200;
		bool init(PieceColor piece_color);
		void select_piece();
		void quit();

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		std::unordered_map <PieceTypeColor, SDL_Texture*, KeyHasherPiece> m_piece_textures;
		void loadAsset(const char*, const PieceType, const PieceColor, const int x, const int y);
	
	};
}