#pragma once
#include <piece_color.h>
#include <piece_type.h>
#include <Coor.h>

namespace chess {
	class Piece {
	protected:
		PieceType m_piece_type;
	public:
		const PieceColor m_piece_color;

		Piece(PieceColor piece_color, Coor piece_position) :m_piece_color(piece_color), m_position(piece_position){};
		virtual ~Piece() {};
		virtual bool can_move(int, int) = 0;
		virtual void update_position(int, int) = 0;
		
		PieceType get_piece_type() {
			return m_piece_type;
		};
		Coor m_position;
	
		
	};
}
