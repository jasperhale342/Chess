#pragma once
#include <piece_color.h>
#include <piece_type.h>
#include <Coor.h>

namespace chess {
	class Piece {
	protected:
		const PieceColor m_piece_color;
		const PieceType m_piece_type;
		Piece(PieceColor piece_color, PieceType piece_type) :m_piece_color(piece_color), m_piece_type(piece_type) {};
		virtual bool canMove(Coor coor);
		
	};
}
