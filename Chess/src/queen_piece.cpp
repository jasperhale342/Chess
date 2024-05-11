#include <queen_piece.h>
#include <coor.h>

namespace chess {
	QueenPiece::QueenPiece(PieceColor piece_color, Coor piece_position) :Piece(piece_color, piece_position) { m_piece_type = QUEEN; };
	QueenPiece::~QueenPiece() {};

	bool QueenPiece::can_move(int x, int y) {
		return true;
	}
	void QueenPiece::update_position(int x, int y) {

	}

}