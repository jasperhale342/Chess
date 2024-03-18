#pragma once
#include <unordered_map>
#include <array>
#include <piece.h>
#include <coor.h>
#include <custom_hash_coor.h>

namespace chess {
	class Board {
	public:
		std::unordered_map <Coor, Piece *, KeyHasherCoor> piece_positions;
		Board(bool is_white);
		void init();
		bool can_move_piece(int x, int y);
		void update_position(int x, int y, Piece* piece);
		void intialize_pieces(PieceColor color, bool is_bottom);
		void create_piece(int x, int y, Piece*);
		void initialize_ponds(int y, PieceColor color);

		

	};
}