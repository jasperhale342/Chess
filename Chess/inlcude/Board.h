#pragma once
#include <vector>
#include <array>

namespace chess {
	class Board {
	private:
		std::vector<std::vector<int>> piecePositions;
		bool isGrabbing;

	public:
		Board();
		void init();
		bool canGrab();
		void updatePositions();
		

	};
}