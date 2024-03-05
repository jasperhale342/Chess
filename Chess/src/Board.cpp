#include <Board.h>
#include <iostream>


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

	void Board::init() {

	}
	bool Board::can_move_piece(int x, int y) {
		return true;
	}

	void Board::update_position(int x, int y) {

	}

	void  Board::intialize_top(PieceColor color) {


	};
	void Board::intialize_bottom(PieceColor color) {
		// initialize king
		Piece * kingPiece = new KingPiece(color, KING);
		
		int x = 0;
		int y = 700;
		
		if (color == WHITE) {
			x = 400;
			
		}
		else {
			x = 300;
		}
			
		
		Coor kingCoor = {x,y};
		std::pair<Coor, Piece*> p = { kingCoor , kingPiece };
	
		piece_positions.emplace(p);
		std::cout << (*piece_positions[kingCoor]).m_piece_color << std::endl;

		// intialize Queen
	
	
	};
}