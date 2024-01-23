#pragma once
struct Coor {
	int x;
	int y;

	bool operator==(const Coor& other) const {
		return (x == other.x && y == other.y);
	}

};


