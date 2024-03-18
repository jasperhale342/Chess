#include <knight_piece.h>
#include <coor.h>

namespace chess {
	KnightPiece::KnightPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position) :Piece(piece_color, piece_type, piece_position) {};
	KnightPiece::~KnightPiece() {};

	bool KnightPiece::can_move(int x, int y) {
		return true;
	}

}