#include <rook_piece.h>
#include <coor.h>

namespace chess {
	RookPiece::RookPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position):Piece(piece_color, piece_type, piece_position) {};
	RookPiece::~RookPiece() {};

	bool RookPiece::can_move(int x, int y) {
		return true;
	}

}