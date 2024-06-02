#include <Board.h>
#include <iostream>
#include <king_piece.h>
#include <queen_piece.h>
#include <rook_piece.h>
#include <bishop_piece.h>
#include <knight_piece.h>
#include <pond_piece.h>
#include <SDL_events.h>
#include <algorithm>  

namespace chess {

	Board::Board()
	{}
	
	Board::Board(bool player_1_is_white) 
	{
		if (player_1_is_white) 
		{
			intialize_pieces(WHITE, true);
			//intialize_pieces(BLACK, false);
		}
		else 
		{
			intialize_pieces(BLACK, true);
			intialize_pieces(WHITE, false);
		}
	}

	bool Board::is_king_in_check(bool turn) 
	{
		return false;
	}

	BOARD_RESPONSE Board::if_able_to_move_piece_then_move_piece(Coor src, Coor des, Piece * piece) 
	{
		// this order matters for the following if statement
		if (can_move_to_position(des) && !is_king_in_check(m_is_white_turn)) 
		{
			switch (piece->get_piece_type()) 
			{
				case POND: {
					// move forward by 1
					// move forward by 2
					// take diagnoally only if there is another piece there of the opposite color
					if ((!is_another_piece_along_Y(src, des.y) || can_take_with_pond(des)) && piece->can_move(src, des)) {
						//Piece* en_passant_piece = piece_positions.at({ x, y + 100 }); // could make this a function
						//if (en_passant_piece->get_piece_type() == POND) {
						//	PondPiece* en_passant_pond = dynamic_cast<PondPiece*>(en_passant_piece);
						//	if (en_passant_pond->is_en_passantable) {
						//		remove_piece({ x, y + 100 });
						//		return BOARD_RESPONSE::YES;
						//	}
						//}
						update_position(des, piece);
						return BOARD_RESPONSE::YES;
					}

					if (des.y == 0) {
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
						update_position(des, piece);
						return BOARD_RESPONSE::YES;
					}

					break;
				}
				default:
					update_position(des, piece);
					return BOARD_RESPONSE::YES;

				}
		}
	
		update_position(src, piece);
		return BOARD_RESPONSE::NO;
	}
	
	bool Board::is_another_piece_there(Coor coor) 
	{
		auto piece = piece_positions.find(coor);
		if (piece != piece_positions.end()) 
		{
			return true;
		}
		return false;
	}
	bool Board::is_another_piece_along_diagnol(Coor src, Coor des) 
	{
		return false;
	}

	bool Board::is_another_piece_along_X(int src_x, int des_x) 
	{
		return false;
	};

	bool Board::is_another_piece_along_Y(Coor src, int des_y) 
	{
		if (src.y != des_y) 
		{
			return false;
		}
		int start = std::min(src.y, des_y) + 100;
		int end = abs(src.y - des_y);
		
		for (int i = start; i < end; i+=100) 
		{
			if (piece_positions.find({ src.x, i }) != piece_positions.end()) 
			{
				return true;
			}
		}
		return false;
	};

	bool Board::can_move_to_position(Coor coor) 
	{
		PieceColor turn = WHITE;
		if (m_is_white_turn) 
		{
			turn = BLACK;
		}
		auto piece = piece_positions.find(coor);
		if (piece != piece_positions.end() && piece->second->m_piece_color == turn) {
			return false;
		}
		return true;
	}

	bool Board::can_take_with_pond(Coor coor) 
	{

		PieceColor turn = WHITE;
		if (m_is_white_turn) 
		{
			turn = BLACK;
		}

		auto piece = piece_positions.find(coor);
		if (piece != piece_positions.end() && piece->second->m_piece_color != turn) 
		{
			return true;
		}
		return false;
	}

	void Board::update_position(Coor des, Piece* piece) 
	{
		//check if a piece is already there, remove that piece etc
		std::pair<Coor, Piece*> p = { des , piece };
		piece_positions.emplace(p);
	}

	void Board::intialize_pieces(PieceColor color, bool is_bottom) 
	{
		int y;
		int pondsPosition = 1;
		if (is_bottom) 
		{
			y = 300;
			pondsPosition = -1;
		}
		else 
		{
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
		//Piece* bishopLeftPiece = new BishopPiece(color);
		//Piece* bishopRightPiece = new BishopPiece(color);
		//insert_piece(200, y, bishopLeftPiece);
		//insert_piece(500, y, bishopLeftPiece);

		//intialize Pond
		
		initialize_ponds(y+ (100* pondsPosition), color);
	};

	void Board::insert_piece(Coor des, Piece* piece) 
	{
		std::pair<Coor, Piece*> coorPiece = { des ,  piece };
		piece_positions.emplace(coorPiece);

	}

	void Board::remove_piece(Coor coor) 
	{
		piece_positions.erase(coor);
	}

	std::unordered_map<Coor, Piece*>::iterator Board::get_piece_iterator(Coor coor)
	{
		return piece_positions.find(coor);
	}

	std::unordered_map<Coor, Piece*>::iterator Board::get_end_iterator_of_piece_posistions()
	{
		return piece_positions.end();
	}

	std::unordered_map<Coor, Piece*>::iterator Board::get_begin_iterator_of_piece_posistions()
	{
		return piece_positions.begin();
	}

	Piece* Board::find_piece(Coor coor) 
	{
		return piece_positions.at(coor);
	}

	void Board::reset_positions() 
	{
		piece_positions.clear();
		intialize_pieces(WHITE, true);
	}

	void Board::promote_pond(Coor des, PieceType pieceType) 
	{
		remove_piece(des);
		PieceColor turn = WHITE;
		if (!m_is_white_turn) 
		{
			turn = BLACK;
		}
		
		Piece* piece = nullptr;
		switch (pieceType) 
		{
			case QUEEN:
				piece = new QueenPiece(turn);
				break;

			case ROOK:
				piece = new RookPiece(turn);
				break;	
		
			case BISHOP:
				piece = new BishopPiece(turn);
				break;

			default:
				//knight
				piece = new KnightPiece(turn);
		}
		insert_piece(des, piece);
	}
	void Board::initialize_ponds(int y, PieceColor color) 
	{
		int x = 0;
		for (int i = 0; i < 8; ++i) 
		{
			Coor coor = { x, y };
			Piece* pond = new PondPiece(color);
			std::pair<Coor, Piece*> pondPair = { coor ,  pond };
			piece_positions.emplace(pondPair);
			x += 100;
		}
	}
}