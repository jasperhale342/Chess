#pragma once
#include <Piece.h>

namespace chess {
	class QueenPiece : public Piece {
	private:
		//PieceType type = 
	public:
		QueenPiece(PieceColor piece_color);
		~QueenPiece();
		virtual bool can_move(Coor src, Coor des) override;
	};
}