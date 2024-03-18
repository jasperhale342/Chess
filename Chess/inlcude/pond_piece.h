#pragma once
#include <Piece.h>

namespace chess {
	class PondPiece : public Piece {
	public:
		PondPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position);
		~PondPiece();
		virtual bool can_move(int x, int y) override;
		bool is_first_move = true;
	};
}