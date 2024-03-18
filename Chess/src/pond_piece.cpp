#include <pond_piece.h>
#include <coor.h>

namespace chess {
	PondPiece::PondPiece(PieceColor piece_color, PieceType piece_type, Coor piece_position) :Piece(piece_color, piece_type, piece_position) {};
	PondPiece::~PondPiece() {};

	bool PondPiece::can_move(int x, int y) {
		// move forward
		if (m_position.x )
		return true;
	}

}