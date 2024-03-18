#include <queen_piece.h>
#include <coor.h>

namespace chess {
	QueenPiece::QueenPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position) :Piece(piece_color, piece_type, piece_position) {};
	QueenPiece::~QueenPiece() {};

	bool QueenPiece::can_move(int x, int y) {
		return true;
	}

}