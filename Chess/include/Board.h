#pragma once
#include <unordered_map>
#include <array>
#include <piece.h>
#include <coor.h>
#include <custom_hash_coor.h>
#include <board_piece_move_response.h>

namespace chess {
	class Board {
	public:
		void remove_piece(Coor coor);
		void reset_positions();
		Piece* find_piece(Coor coor);
		std::unordered_map<Coor, Piece*>::iterator get_piece(Coor coor);
		std::unordered_map<Coor, Piece*>::iterator get_end_iterator();
		std::unordered_map<Coor, Piece*>::iterator get_begin_iterator();
		Board(bool is_white);
		void init();
		BOARD_RESPONSE can_move_piece(int x, int y, Piece* piece);
		void update_position(int x, int y, Piece* piece);
		
		void insert_piece(int x, int y, Piece*);
		void create_piece_from_pond(int x, int y, PieceType pieceType, PieceColor color);
		void promote_pond();
	
		bool white_en_passantable = false;
		bool black_en_passantable = false;
		// dont think this is the best idea because there is more state to keep track of
		//Piece* white_en_passantable_pond = nullptr;
	private:
		// make things const
		PieceColor m_player_1; 
		PieceColor m_player_2;
		std::unordered_map <Coor, Piece*, CoorKeyHasher> piece_positions;
		bool is_king_in_check(bool turn);
		bool can_move_to_position(Coor coor);
		bool is_same_color_piece_there(Coor coor);

		bool is_another_piece_in_the_way(Coor src, Coor des);

		bool is_another_piece_along_X(Coor src, Coor des);
		bool is_another_piece_along_Y(Coor coor);
		bool is_a_piece_there(Coor coor);
		bool can_move_piece(Coor coor);
		bool can_take_with_pond(Coor coor);
		void intialize_pieces(PieceColor color, bool is_bottom);
		void initialize_ponds(int y, PieceColor color);
		bool m_is_white_turn = true;
		

	};
}