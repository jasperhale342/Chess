#pragma once
#include <Piece.h>

namespace chess {
	class QueenPiece : public Piece {
	private:
		//PieceType type = 
	public:
		QueenPiece(PieceColor piece_color,  Coor piece_position);
		~QueenPiece();
		virtual bool can_move(int, int) override;
		virtual void update_position(int, int) override;
	};
}