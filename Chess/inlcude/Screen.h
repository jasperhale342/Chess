#pragma once
#include <SDL.h>
#include <unordered_map>
#include <piece.h>
#include <coor.h>
#include <custom_hash_piece.h>
#include <iostream>
#include <custom_hash_coor.h>
#include <board.h>

namespace chess {
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 800;
		const static SDL_Rect BOARD_DIMENSION;
		const static SDL_Rect PIECE_DIMENSION;
		const static SDL_Rect BOARD_POSITION;
		
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_board_texture;
		std::unordered_map <PieceType, SDL_Texture*, KeyHasherPiece> m_piece_textures;
		bool isGrabbing;
		Board chessBoard;
		Coor piece_to_move;
		SDL_Texture* piece_to_move_texture;

	public:
		Screen();
		void update();
		void renderBoard() const;
		bool init();
		bool processSDLEvents();
		bool canGrab(int, int);
		int calculateSlot(int x);
		void close();
		void clear();
	


	};
}