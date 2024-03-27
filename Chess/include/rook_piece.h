#pragma once
#include <Piece.h>

namespace chess {
	class RookPiece : public Piece {
	public:
		RookPiece(PieceColor piece_color, Coor piece_position);
		~RookPiece();
		virtual bool can_move(int, int) override;
		virtual void update_position(int, int) override;
	};
}