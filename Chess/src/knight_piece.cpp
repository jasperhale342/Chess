#include <knight_piece.h>
#include <coor.h>

namespace chess {
	KnightPiece::KnightPiece(PieceColor piece_color, Coor piece_position) :Piece(piece_color, piece_position) {};
	KnightPiece::~KnightPiece() {};

	bool KnightPiece::can_move(int x, int y) {
		return true;
	}
	void KnightPiece::update_position(int x, int y) {

	}

}