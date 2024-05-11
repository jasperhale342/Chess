#include <king_piece.h>
#include <coor.h>

namespace chess {
	KingPiece::KingPiece(PieceColor piece_color,  Coor piece_position) :Piece(piece_color, piece_position) { m_piece_type = KING; };
	KingPiece::~KingPiece() {};
	
	bool KingPiece::can_move(int x, int y) {
		return true;
	}
	void KingPiece::update_position(int x, int y) {

	}
	
}