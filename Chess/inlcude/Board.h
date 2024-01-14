#pragma once
#include <unordered_map>
#include <array>
#include <piece.h>
#include <coor.h>

namespace chess {
	class Board {
	private:
		std::unordered_map <Coor, Piece> piece_positions;
		bool is_grabbing;
		void intialize_top(PieceColor color);
		void intialize_bottom(PieceColor color);
		

	public:
		Board(bool is_white);
		void init();
		bool can_grab();
		void update_position(Coor coor);

		

	};
}