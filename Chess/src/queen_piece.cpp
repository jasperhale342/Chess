#include <queen_piece.h>
#include <coor.h>

namespace chess {
	QueenPiece::QueenPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	QueenPiece::~QueenPiece() {};

	bool QueenPiece::canMove(Coor coor) {
		return true;
	}

}