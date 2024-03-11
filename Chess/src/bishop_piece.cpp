#include <bishop_piece.h>
#include <coor.h>

namespace chess {
	BishopPiece::BishopPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	BishopPiece::~BishopPiece() {};

	bool BishopPiece::canMove(Coor coor) {
		return true;
	}

}