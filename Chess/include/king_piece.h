#pragma once
#include <Piece.h>

namespace chess {
	class KingPiece : public Piece {
	public:
		KingPiece(PieceColor piece_color, Coor piece_position);
		~KingPiece();
		virtual bool can_move(int, int) override;
		virtual void update_position(int, int) override;
	};
}