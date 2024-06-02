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
		Piece(PieceColor piece_color) :m_piece_color(piece_color){};
		virtual ~Piece() {};
		virtual bool can_move(Coor src, Coor des) = 0;
		PieceType get_piece_type() {
			return m_piece_type;
		};
	

		
	
		
	};
}
