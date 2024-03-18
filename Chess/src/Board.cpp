#include <Board.h>
#include <iostream>
#include <king_piece.h>
#include <queen_piece.h>
#include <rook_piece.h>
#include <bishop_piece.h>
#include <knight_piece.h>
#include <pond_piece.h>

namespace chess {
	Board::Board(bool is_white) {

		if (is_white) {
			intialize_pieces(WHITE, true);
			intialize_pieces(BLACK, false);
			
		}
		else {
			// initialize_bottom(Black)
			// intialize_top(White)
		}

	}

	void Board::init() {

	}
	bool Board::can_move_piece(int x, int y) {
		return true;
	}

	void Board::update_position(int x, int y, Piece* piece) {
		//check if a piece is already there, remove that piece etc
		Coor coor = { x,y };
		std::pair<Coor, Piece*> p = { coor , piece };
		piece_positions.emplace(p);
	}

	
	void Board::intialize_pieces(PieceColor color, bool is_bottom) {
	
		int y;
		int pondsPosition = 1;
		if (is_bottom) {
			y = 500;
			pondsPosition = -1;
			
		}
		else {
			y = 0;
			
		}
		//initialize king piece
		Piece* kingPiece = new KingPiece(color, KING, {400,y});
		create_piece(400, y, kingPiece);
		
		//initialize queen piece
		Piece* queenPiece = new QueenPiece(color, QUEEN, {300, y});
		create_piece(300, y, queenPiece);

		//initialize rook pieces
		Piece* rookLeftPiece = new RookPiece(color, ROOK, {0,y});
		Piece* rookRightPiece = new RookPiece(color, ROOK, {700, y});
		create_piece(0, y, rookLeftPiece);
		create_piece(700, y, rookRightPiece);

		//initialize Knights
		Piece* knightLeftPiece = new KnightPiece(color, KNIGHT, {100, y});
		Piece* knightRightPiece = new KnightPiece(color, KNIGHT, {600, y});
		create_piece(100, y, knightLeftPiece);
		create_piece(600, y, knightRightPiece);

		//intialize Bishops
		Piece* bishopLeftPiece = new BishopPiece(color, BISHOP, {200,y});
		Piece* bishopRightPiece = new BishopPiece(color, BISHOP, {500,y});
		create_piece(200, y, bishopLeftPiece);
		create_piece(500, y, bishopLeftPiece);

		//intialize Pond
		
		initialize_ponds(y+ (100* pondsPosition), color);

	
	
	};
	void Board::create_piece(int x, int y, Piece* piece) {

		Coor coor = { x,y };
		std::pair<Coor, Piece*> pairRookRight = { coor ,  piece };
		piece_positions.emplace(pairRookRight);

	}
	void Board::initialize_ponds(int y, PieceColor color) {
		int x = 0;
		for (int i = 0; i < 8; ++i) {
			Coor coor = { x, y };
			Piece* pond = new PondPiece(color, POND, {x,y});
			std::pair<Coor, Piece*> pondPair = { coor ,  pond };
			piece_positions.emplace(pondPair);
			x += 100;
		}
	}
}