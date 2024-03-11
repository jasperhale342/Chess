#include <rook_piece.h>
#include <coor.h>

namespace chess {
	RookPiece::RookPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	RookPiece::~RookPiece() {};

	bool RookPiece::canMove(Coor coor) {
		return true;
	}

}