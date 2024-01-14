#include <Board.h>
#include <king_piece.h>


namespace chess {
	Board::Board(bool is_white) {

		if (is_white) {
			intialize_bottom(WHITE);
			// initialize_top(black)
		}
		else {
			// initialize_bottom(Black)
			// intialize_top(White)
		}
		// initialize kings
	

	}

	void Board::update_position(Coor coor) {

	}

	void  Board::intialize_top(PieceColor color) {


	};
	void Board::intialize_bottom(PieceColor color) {
		// initialize king
		KingPiece kingPiece(color, KING);
		Coor kingCoor;
		if (color == WHITE) {
			kingCoor.x = 400;
			kingCoor.y = 700;
		}
		else {
			kingCoor.x = 300;
			kingCoor.y = 700;
		}
		std::pair<Coor, Piece> p(kingCoor, kingPiece);
		piece_positions.insert(p);
		// intialize Queen
	
	
	};
}