#pragma once
#include <Piece.h>

namespace chess {
	class PondPiece : public Piece {
	public:
		PondPiece(PieceColor piece_color, PieceType piece_type);
		~PondPiece();
		virtual bool canMove(Coor coor) override;
	};
}