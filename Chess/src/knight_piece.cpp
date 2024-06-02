#include <knight_piece.h>
#include <coor.h>

namespace chess {
	KnightPiece::KnightPiece(PieceColor piece_color) :Piece(piece_color) { m_piece_type = KNIGHT; };
	KnightPiece::~KnightPiece() {};

	bool KnightPiece::can_move(Coor src, Coor des) {
		return true;
	}


}