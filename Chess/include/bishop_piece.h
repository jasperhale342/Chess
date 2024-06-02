#pragma once
#include <Piece.h>

namespace chess {
	class BishopPiece : public Piece {
	public:
		BishopPiece(PieceColor piece_color);
		~BishopPiece();
		virtual bool can_move(Coor src, Coor des) override;
		
	};
}