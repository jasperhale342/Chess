#pragma once
#include <SDL.h>
#include <unordered_map>
#include <piece.h>
#include <coor.h>
#include <custom_hash_piece.h>
#include <iostream>
#include <custom_hash_coor.h>

namespace chess {
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 800;
		const static SDL_Rect BOARD_DIMENSION;
		const static SDL_Rect BOARD_POSITION;
		
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_board_texture;
		std::unordered_map <PieceType, SDL_Texture*, KeyHasherPiece> m_piece_textures;
		bool isGrabbing;
		Sint32 mouseX;
		Sint32 mouseY;

	public:
		Screen();
		void update();
		void renderBoard(const std::unordered_map<Coor, Piece*, KeyHasherCoor>) const;
		bool init();
		bool processSDLEvents();
		bool canGrab();
		int calculateSlot();
		void close();
		void clear();
	


	};
}