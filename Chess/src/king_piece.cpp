#include <king_piece.h>

namespace chess {
	KingPiece::KingPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	
	bool KingPiece::canMove(Coor coor) {
		return false;
	}
	
}