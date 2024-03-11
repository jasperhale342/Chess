#include <pond_piece.h>
#include <coor.h>

namespace chess {
	PondPiece::PondPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	PondPiece::~PondPiece() {};

	bool PondPiece::canMove(Coor coor) {
		return true;
	}

}