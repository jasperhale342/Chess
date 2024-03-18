#include <bishop_piece.h>
#include <coor.h>

namespace chess {
	BishopPiece::BishopPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position) :Piece(piece_color, piece_type, piece_position) {};
	BishopPiece::~BishopPiece() {};

	bool BishopPiece::can_move(int x, int y) {
		return true;
	}

}