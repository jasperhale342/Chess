#pragma once
#include <Piece.h>

namespace chess {
	class QueenPiece : public Piece {
	public:
		QueenPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position);
		~QueenPiece();
		virtual bool can_move(int, int) override;
	};
}