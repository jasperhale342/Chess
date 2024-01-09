#pragma once
#include <vector>
#include <array>

namespace chess {
	class Board {
	private:
		std::vector<std::vector<int>> piecePositions;
		final std::array int[8][8] gridSlot;
		bool isGrabbing;

	public:
		void init();
		bool canGrab();
		void updatePositions();
		void 

	};
}