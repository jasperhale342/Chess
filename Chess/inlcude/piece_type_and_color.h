#pragma once
#include <piece_color.h>
#include <piece_type.h>
struct PieceTypeColor {
	PieceType type;
	PieceColor color;
	bool operator==(const PieceTypeColor& other) const {
		return (type == other.type && color == other.color);
	}
	friend std::ostream& operator<<(std::ostream& os, const PieceTypeColor& ptc) {
		os << "Piece type: " << ptc.type << ", Piece color:" << ptc.color << std::endl;
		return os;
	}
};