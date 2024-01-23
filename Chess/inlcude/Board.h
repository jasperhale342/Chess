#pragma once
#include <unordered_map>
#include <array>
#include <piece.h>
#include <king_piece.h>
#include <coor.h>
#include <custom_hash.h>

namespace chess {
	class Board {
	public:
		std::unordered_map <Coor, Piece, KeyHasher> piece_positions;
		Board(bool is_white);
		void init();
		bool can_grab();
		void update_position(Coor coor);
		void intialize_top(PieceColor color);
		void intialize_bottom(PieceColor color);

		

	};
}