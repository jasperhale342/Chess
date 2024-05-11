#include <bishop_piece.h>
#include <coor.h>

namespace chess {
	BishopPiece::BishopPiece(PieceColor piece_color,Coor piece_position) :Piece(piece_color, piece_position) { m_piece_type = BISHOP; };
	BishopPiece::~BishopPiece() {};

	bool BishopPiece::can_move(int x, int y) {
		return true;
	}
	void BishopPiece::update_position(int x, int y) {

	}

}