#pragma once
#include <piece_color.h>
#include <piece_type.h>
#include <Coor.h>

namespace chess {
	class Piece {
	private:
		

	public:
		const PieceColor m_piece_color;
		const PieceType m_piece_type;
		
		Piece(PieceColor piece_color, PieceType piece_type, Coor piece_position) :m_piece_color(piece_color), m_piece_type(piece_type), m_position(piece_position){};
		virtual ~Piece() {};
		virtual bool can_move(int, int) = 0;
		Coor m_position;
	
		
	};
}
