#pragma once
#include <ostream>
struct Coor {
	int x;
	int y;

	bool operator==(const Coor& other) const {
		return (x == other.x && y == other.y);
	}
	friend std::ostream& operator<<(std::ostream& os, const Coor& c) {
		os << "Coor is: " <<c.x << ", " << c.y << std::endl;
		return os;
	}

};


