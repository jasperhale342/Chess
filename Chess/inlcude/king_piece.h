#pragma once
#include <Piece.h>

namespace chess {
	class KingPiece : public Piece {
	public:
		KingPiece(PieceColor piece_color, PieceType piece_type);
		~KingPiece();
		virtual bool canMove(Coor coor) override;
	};
}