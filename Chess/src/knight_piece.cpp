#include <knight_piece.h>
#include <coor.h>

namespace chess {
	KnightPiece::KnightPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	KnightPiece::~KnightPiece() {};

	bool KnightPiece::canMove(Coor coor) {
		return true;
	}

}