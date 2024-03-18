#pragma once
#include <Piece.h>

namespace chess {
	class KnightPiece : public Piece {
	public:
		KnightPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position);
		~KnightPiece();
		virtual bool can_move(int, int) override;
	};
}