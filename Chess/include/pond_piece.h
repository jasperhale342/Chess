#pragma once
#include <Piece.h>

namespace chess {
	class PondPiece : public Piece {
	public:
		PondPiece(PieceColor piece_color);
		~PondPiece();
		virtual bool can_move(Coor src, Coor des) override;
		bool is_first_move = true;
		bool is_en_passantable = false;

	};
}