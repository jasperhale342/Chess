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
		void intialize_top(PieceColor color);
		void intialize_bottom(PieceColor color);

		

	};
}