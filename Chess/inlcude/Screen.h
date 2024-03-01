#pragma once
#include <SDL.h>
#include <unordered_map>
#include <piece.h>
#include <coor.h>
#include <custom_hash_piece.h>

namespace chess {
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 800;
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		std::unordered_map <PieceType, SDL_Texture*, KeyHasherPiece> m_piece_textures;

	public:
		Screen();
		void update();
		void renderBoard(const std::unordered_map<Coor, Piece*>);
		bool init();
		bool processSDLEvents();
		bool isGrabbing();
		void close();
		void clear();
	


	};
}