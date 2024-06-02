#pragma once
#include <Piece.h>

namespace chess {
	class KingPiece : public Piece {
	public:
		KingPiece(PieceColor piece_color);
		~KingPiece();
		virtual bool can_move(Coor src, Coor des) override;

	};
}