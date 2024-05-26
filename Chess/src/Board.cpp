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

	bool Board::is_king_in_check(bool turn) {
		return false;
	}

	BOARD_RESPONSE Board::can_move_piece(int x, int y, Piece * piece) {
		// this order matters for the following if statement
		if (can_move_to_position({ x,y }) && !is_king_in_check(m_is_white_turn)) {
			switch (piece->get_piece_type()) {
			case POND:
				if (piece->can_move(x, y)) {

				}
				
				if (y == 0) {
					return BOARD_RESPONSE::PROMOTE_POND;
				}
				PondPiece* pond = dynamic_cast<PondPiece*>(piece);
				if (pond->is_en_passantable) {
					if (m_is_white_turn) {
						white_en_passantable = true;
					}
					else {
						black_en_passantable = true;
					}
					return BOARD_RESPONSE::YES;
				}
				
				else {
					Piece* en_passant_piece = piece_positions.at({ x, y + 100 }); // could make this a function
					if (en_passant_piece->get_piece_type() == POND) {
						PondPiece* en_passant_pond = dynamic_cast<PondPiece*>(en_passant_piece);
						if (en_passant_pond->is_en_passantable) {
							remove_piece({ x, y + 100 });
							return BOARD_RESPONSE::YES;
						}
					}
				}

				break;
			default:

				return BOARD_RESPONSE::YES;

			}
		}
	

		return BOARD_RESPONSE::NO;
	}
	

	bool Board::is_another_piece_in_the_way(Coor src, Coor des) {

	}

	bool Board::is_another_piece_along_X(Coor src, Coor dest) {
	
	
	};

	bool Board::is_another_piece_along_Y(Coor coor) {

	};


	bool Board::can_move_to_position(Coor coor) {
		
		PieceColor turn = WHITE;
		if (m_is_white_turn) {
			turn = BLACK;
		}
		auto piece = piece_positions.find(coor);
		if (piece != piece_positions.end() && piece->second->m_piece_color == turn) {
			return false;
		}
		return true;
	}
	bool Board::can_take_with_pond(Coor coor) {
		PieceColor turn = WHITE;
		if (m_is_white_turn) {
			turn = BLACK;
		}
		auto piece = piece_positions.find(coor);
		if (piece != piece_positions.end() && piece->second->m_piece_color != turn) {
			return true;
		}
		return false;

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
			y = 300;
			pondsPosition = -1;
			
		}
		else {
			y = 0;
			
		}
		////initialize king piece
		//Piece* kingPiece = new KingPiece(color, {400,y});
		//insert_piece(400, y, kingPiece);
		//
		////initialize queen piece
		//Piece* queenPiece = new QueenPiece(color,  {300, y});
		//insert_piece(300, y, queenPiece);

		////initialize rook pieces
		//Piece* rookLeftPiece = new RookPiece(color, {0,y});
		//Piece* rookRightPiece = new RookPiece(color, {700, y});
		//insert_piece(0, y, rookLeftPiece);
		//insert_piece(700, y, rookRightPiece);

		////initialize Knights
		//Piece* knightLeftPiece = new KnightPiece(color,  {100, y});
		//Piece* knightRightPiece = new KnightPiece(color, {600, y});
		//insert_piece(100, y, knightLeftPiece);
		//insert_piece(600, y, knightRightPiece);

		////intialize Bishops
		//Piece* bishopLeftPiece = new BishopPiece(color, {200,y});
		//Piece* bishopRightPiece = new BishopPiece(color, {500,y});
		//insert_piece(200, y, bishopLeftPiece);
		//insert_piece(500, y, bishopLeftPiece);

		//intialize Pond
		
		initialize_ponds(y+ (100* pondsPosition), color);

	
	
	};
	void Board::insert_piece(int x, int y, Piece* piece) {

		Coor coor = { x,y };
		std::pair<Coor, Piece*> coorPiece = { coor ,  piece };
		piece_positions.emplace(coorPiece);

	}
	void Board::remove_piece(Coor coor) {
		piece_positions.erase(coor);
	}
	std::unordered_map<Coor, Piece*>::iterator Board::get_piece(Coor coor) {
		return piece_positions.find(coor);
	}
	std::unordered_map<Coor, Piece*>::iterator Board::get_end_iterator() {
		return piece_positions.end();
	}
	std::unordered_map<Coor, Piece*>::iterator Board::get_begin_iterator() {
		return piece_positions.begin();
	}
	Piece* Board::find_piece(Coor coor) {
		return piece_positions[coor];
	}
	void Board::reset_positions() {
		piece_positions.clear();
		intialize_pieces(WHITE, true);
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
			piece = new BishopPiece(color, { x, y });
			break;


		default:
			//knight
			piece = new KnightPiece(color, { x, y });
		}

		insert_piece(x, y, piece);
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