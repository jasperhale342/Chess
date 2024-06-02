#pragma once
#include <unordered_map>
#include <array>
#include <piece.h>
#include <coor.h>
#include <custom_hash_coor.h>
#include <board_piece_move_response.h>

namespace chess 
{
	class Board 
	{
		public:
			Board();
			Board(bool player_1_is_white);

			Piece* find_piece(Coor coor);

			void promote_pond(Coor des, PieceType pieceType);
			void remove_piece(Coor coor);
			void reset_positions();
			void insert_piece(Coor des, Piece*);
		
			std::unordered_map<Coor, Piece*>::iterator get_piece_iterator(Coor coor);
			std::unordered_map<Coor, Piece*>::iterator get_end_iterator_of_piece_posistions();
			std::unordered_map<Coor, Piece*>::iterator get_begin_iterator_of_piece_posistions();
		
			BOARD_RESPONSE if_able_to_move_piece_then_move_piece(Coor src, Coor des, Piece* piece);
	
		private:
			// make things const
			PieceColor m_player_1; 
			PieceColor m_player_2;

			bool white_en_passantable = false;
			bool black_en_passantable = false;
			bool m_is_white_turn = true;

			std::unordered_map <Coor, Piece*, CoorKeyHasher> piece_positions;

		private:
			void update_position(Coor des, Piece* piece);
			
			void intialize_pieces(PieceColor color, bool is_bottom);
			void initialize_ponds(int y, PieceColor color);

			bool is_king_in_check(bool turn);
			bool can_move_to_position(Coor coor);
			bool is_another_piece_there(Coor coor);
			bool is_another_piece_along_diagnol(Coor src, Coor des);
			bool is_another_piece_along_X(int src_x, int des_x);
			bool is_another_piece_along_Y(Coor src, int des_y);
			bool can_take_with_pond(Coor coor);
	};
}