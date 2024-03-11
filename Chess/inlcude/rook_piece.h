#pragma once
#include <Piece.h>

namespace chess {
	class RookPiece : public Piece {
	public:
		RookPiece(PieceColor piece_color, PieceType piece_type);
		~RookPiece();
		virtual bool canMove(Coor coor) override;
	};
}