#pragma once
#include <Piece.h>

namespace chess {
	class BishopPiece : public Piece {
	public:
		BishopPiece(PieceColor piece_color, Coor piece_position);
		~BishopPiece();
		virtual bool can_move(int, int) override;
		virtual void update_position(int, int)override;
	};
}