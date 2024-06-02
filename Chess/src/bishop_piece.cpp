#include <bishop_piece.h>
#include <coor.h>

namespace chess {
	BishopPiece::BishopPiece(PieceColor piece_color) :Piece(piece_color) { m_piece_type = BISHOP; };
	BishopPiece::~BishopPiece() {};

	bool BishopPiece::can_move(Coor src, Coor des) {
		return true;
	}
	

}