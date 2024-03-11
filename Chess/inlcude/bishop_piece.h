#pragma once
#include <Piece.h>

namespace chess {
	class BishopPiece : public Piece {
	public:
		BishopPiece(PieceColor piece_color, PieceType piece_type);
		~BishopPiece();
		virtual bool canMove(Coor coor) override;
	};
}