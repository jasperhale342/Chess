#include <king_piece.h>
#include <coor.h>

namespace chess {
	KingPiece::KingPiece(PieceColor piece_color) :Piece(piece_color) { m_piece_type = KING; };
	KingPiece::~KingPiece() {};
	
	bool KingPiece::can_move(Coor src, Coor des) {
		return true;
	}

	
}