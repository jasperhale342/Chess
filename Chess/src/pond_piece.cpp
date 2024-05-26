#include <pond_piece.h>
#include <coor.h>

namespace chess {
	PondPiece::PondPiece(PieceColor piece_color, Coor piece_position) :Piece(piece_color,  piece_position) {
		m_piece_type = POND;
	};
	PondPiece::~PondPiece() {};

	bool PondPiece::can_move(int x, int y) {
		if (x > 800 || x < 0 || y >800 || y < 0) {
			return false;
		}
		if (m_position.y - y == 100 && m_position.x == x) {
			return true;
		}
		else if (m_position.y - y == 200 && m_position.x == x && is_first_move) {
			is_en_passantable = true;
			return true;
		}
		else if (
			m_position.y - y == 100 && m_position.x  - x == 100 || 
			m_position.y - y == 100 && m_position.x - x == -100) {
			return true;
		} 
		return false;
	}
	void PondPiece::update_position(int x, int y) {
		m_position.x = x;
		m_position.y = y;
		//might be better to have this as a seperate function that way you're not updating it every time a pond piece moves
		is_first_move = false;
		
	}
	
	
	
	/*PieceType PondPiece::get_piece_type() {
		return 
	}*/

}