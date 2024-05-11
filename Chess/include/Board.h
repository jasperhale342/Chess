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
		Piece* get_piece(Coor coor);
		Board(bool is_white);
		void init();
		BOARD_RESPONSE can_move_piece(int x, int y, Piece* piece);
		void update_position(int x, int y, Piece* piece);
		bool is_same_color_piece_there(Coor coor);
		void intialize_pieces(PieceColor color, bool is_bottom);
		void create_piece(int x, int y, Piece*);
		void create_piece_from_pond(int x, int y, PieceType pieceType, PieceColor color);
		void initialize_ponds(int y, PieceColor color);
		bool m_is_white_turn = true;
		void promote_pond();
	private:
		PieceColor m_player_1; 
		PieceColor m_player_2;
		std::unordered_map <Coor, Piece*, KeyHasherCoor> piece_positions;
		

	};
}