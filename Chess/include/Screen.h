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
		
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_board_texture;
		std::unordered_map <PieceTypeColor, SDL_Texture*, KeyHasherPiece> m_piece_textures;
		bool isGrabbing;
		Board chessBoard;
		SDL_Rect piece_to_move = {0,0,100,100};
		SDL_Texture* piece_to_move_texture;
		Piece* piece_to_move_piece_type;
		Coor piece_to_move_prev_pos;
		void loadAsset(const char *, const PieceType, const PieceColor);

	public:
		Screen();
		void update();
		void renderBoard() ;
		bool init();
		bool processSDLEvents();
		bool canGrab(int, int);
		int calculateSlot(int x);
		void close();
		void clear();
	


	};
}