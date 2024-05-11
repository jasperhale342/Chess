#include <rook_piece.h>
#include <coor.h>

namespace chess {
	RookPiece::RookPiece(PieceColor piece_color,  Coor piece_position):Piece(piece_color, piece_position) { m_piece_type = ROOK; };
	RookPiece::~RookPiece() {};

	bool RookPiece::can_move(int x, int y) {
		return true;
	}
	void RookPiece::update_position(int x, int y) {

	}
}