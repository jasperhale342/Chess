#include <boost/test/unit_test.hpp>
#include "custom_hash_coor.h"
#include "coor.h"
#include "pond_piece.h"
#include "rook_piece.h"
#include <unordered_map>
using namespace chess;
BOOST_AUTO_TEST_SUITE(HashersTest)


namespace hashers_test {
	BOOST_AUTO_TEST_CASE(Coor_Hasher_x1_equal_y2_and_x2_equal_y1)
	{
		
		Coor coor1 = {0, 100};
		Coor coor2 = { 100, 0 };
		CoorKeyHasher coor_hasher;
		std::size_t result1 = coor_hasher(coor1);
		std::size_t result2 = coor_hasher(coor2);
		BOOST_TEST(result1 != result2);
		
	}

}
BOOST_AUTO_TEST_SUITE_END()