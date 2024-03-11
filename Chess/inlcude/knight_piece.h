#pragma once
#include <Piece.h>

namespace chess {
	class KnightPiece : public Piece {
	public:
		KnightPiece(PieceColor piece_color, PieceType piece_type);
		~KnightPiece();
		virtual bool canMove(Coor coor) override;
	};
}