#pragma once
#include <SDL.h>
#include <unordered_map>
#include <custom_hash_piece_type.h>
#include <custom_hash_coor.h>
#include <coor.h>
namespace chess {
	class PromtePondModal {
	public: 
		const static int SCREEN_WIDTH = 200;
		const static int SCREEN_HEIGHT = 200;
		bool init();
		void display(int x, int y);
		void close_display();
		Coor get_coordinates();
		PieceType select_piece(int x, int y);
		void quit();

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		std::unordered_map <PieceType, SDL_Texture*, PieceTypeKeyHasher> m_piece_textures;
		std::unordered_map <Coor, PieceType, CoorKeyHasher> m_piece_positions;
		void loadAsset(const char*, const PieceType, const int x, const int y);
	
	};
}