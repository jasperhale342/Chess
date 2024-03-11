#pragma once
#include <Piece.h>

namespace chess {
	class QueenPiece : public Piece {
	public:
		QueenPiece(PieceColor piece_color, PieceType piece_type);
		~QueenPiece();
		virtual bool canMove(Coor coor) override;
	};
}