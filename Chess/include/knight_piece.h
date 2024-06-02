#pragma once
#include <Piece.h>

namespace chess {
	class KnightPiece : public Piece {
	public:
		KnightPiece(PieceColor piece_color);
		~KnightPiece();
		virtual bool can_move(Coor src, Coor des) override;
	};
}