#include <Board.h>
#include <iostream>
#include <king_piece.h>
#include <queen_piece.h>
#include <rook_piece.h>
#include <bishop_piece.h>
#include <knight_piece.h>
#include <pond_piece.h>
#include <SDL_events.h>

namespace chess {
	Board::Board(bool is_white) {

		if (is_white) {
			intialize_pieces(WHITE, true);
			//intialize_pieces(BLACK, false);
			
		}
		else {
			intialize_pieces(BLACK, true);
			intialize_pieces(WHITE, false);
		}

	}

	void Board::init() {

	}
	BOARD_RESPONSE Board::can_move_piece(int x, int y, Piece * piece) {
		if (piece->can_move(x, y) && ! is_same_color_piece_there({x,y})) {
			if (piece->get_piece_type() == POND && piece->m_position.y == 100) {
				
				return BOARD_RESPONSE::PROMOTE_POND;
				
			}
			return BOARD_RESPONSE::YES;
		}
		return BOARD_RESPONSE::NO;
	}
	bool Board::is_same_color_piece_there(Coor coor) {
		
		auto it = piece_positions.find(coor);
		if (it == piece_positions.end()) {
			return false;
		}
		return true;
	}

	void Board::update_position(int x, int y, Piece* piece) {
		//check if a piece is already there, remove that piece etc
		
		Coor coor = { x,y };
		std::pair<Coor, Piece*> p = { coor , piece };
		piece->update_position(x, y);
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
		Piece* kingPiece = new KingPiece(color, {400,y});
		create_piece(400, y, kingPiece);
		
		//initialize queen piece
		Piece* queenPiece = new QueenPiece(color,  {300, y});
		create_piece(300, y, queenPiece);

		//initialize rook pieces
		Piece* rookLeftPiece = new RookPiece(color, {0,y});
		Piece* rookRightPiece = new RookPiece(color, {700, y});
		create_piece(0, y, rookLeftPiece);
		create_piece(700, y, rookRightPiece);

		//initialize Knights
		Piece* knightLeftPiece = new KnightPiece(color,  {100, y});
		Piece* knightRightPiece = new KnightPiece(color, {600, y});
		create_piece(100, y, knightLeftPiece);
		create_piece(600, y, knightRightPiece);

		//intialize Bishops
		Piece* bishopLeftPiece = new BishopPiece(color, {200,y});
		Piece* bishopRightPiece = new BishopPiece(color, {500,y});
		create_piece(200, y, bishopLeftPiece);
		create_piece(500, y, bishopLeftPiece);

		//intialize Pond
		
		initialize_ponds(y+ (100* pondsPosition), color);

	
	
	};
	void Board::create_piece(int x, int y, Piece* piece) {

		Coor coor = { x,y };
		std::pair<Coor, Piece*> coorPiece = { coor ,  piece };
		piece_positions.emplace(coorPiece);

	}
	void Board::remove_piece(Coor coor) {
		piece_positions.erase(coor);
	}
	Piece* Board::get_piece(Coor coor) {
		return piece_positions.at(coor);
	}
	void Board::create_piece_from_pond(int x, int y, PieceType pieceType, PieceColor color) {
		piece_positions.erase({ x, y });
		Piece* piece = nullptr;
		switch (pieceType) {
		case QUEEN:
			piece = new QueenPiece(color, { x, y });
			break;

		case ROOK:
			piece = new RookPiece(color, { x, y });
			break;	
		
		case BISHOP:
			piece = new RookPiece(color, { x, y });
			break;


		default:
			//knight
			piece = new KnightPiece(color, { x, y });
		}
		
		Coor coor = { x,y };
		std::pair<Coor, Piece*> coorPiece = { coor ,  piece };
		piece_positions.emplace(coorPiece);

	}
	void Board::initialize_ponds(int y, PieceColor color) {
		int x = 0;
		for (int i = 0; i < 8; ++i) {
			Coor coor = { x, y };
			Piece* pond = new PondPiece(color,  {x,y});
			std::pair<Coor, Piece*> pondPair = { coor ,  pond };
			piece_positions.emplace(pondPair);
			x += 100;
		}
	}
}