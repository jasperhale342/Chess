#include <pond_piece.h>
#include <coor.h>

namespace chess {
	PondPiece::PondPiece(PieceColor piece_color) :Piece(piece_color) {
		m_piece_type = POND;
	};
	PondPiece::~PondPiece() {};

	bool PondPiece::can_move(Coor src, Coor des) {
		if (des.x > 800 || des.x < 0 || des.y >800 || des.y < 0) {
			return false;
		}
		if (src.y - des.y == 100 && src.x == des.x) {
			is_first_move = false;
			return true;
		}
		else if (src.y - des.y == 200 && src.x == des.x && is_first_move) {
			is_first_move = false;
			is_en_passantable = true;
			return true;
		}
		else if (
			src.y - des.y == 100 && src.x  - des.x == 100 || 
			src.y - des.y == 100 && src.x - des.x == -100) {
			is_first_move = false;
			return true;
		} 
		return false;
	}

}