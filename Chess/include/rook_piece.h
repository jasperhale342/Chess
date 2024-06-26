#pragma once
#include <Piece.h>

namespace chess {
	class RookPiece : public Piece {
	public:
		RookPiece(PieceColor piece_color);
		~RookPiece();
		virtual bool can_move(Coor src, Coor des) override;
		
	};
}