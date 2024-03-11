#include <king_piece.h>
#include <coor.h>

namespace chess {
	KingPiece::KingPiece(PieceColor piece_color, PieceType piece_type) :Piece(piece_color, piece_type) {};
	KingPiece::~KingPiece() {};
	
	bool KingPiece::canMove(Coor coor) {
		return true;
	}
	
}