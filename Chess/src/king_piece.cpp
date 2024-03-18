#include <king_piece.h>
#include <coor.h>

namespace chess {
	KingPiece::KingPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position) :Piece(piece_color, piece_type, piece_position) {};
	KingPiece::~KingPiece() {};
	
	bool KingPiece::can_move(int x, int y) {
		return true;
	}
	
}