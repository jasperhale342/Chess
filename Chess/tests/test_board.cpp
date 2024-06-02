#include <boost/test/unit_test.hpp>
#include "pond_piece.h"
#include "Board.h"

using namespace chess;
namespace test_board_pond
{

	struct BoardPondTestFixture
	{
		Piece* pond = nullptr;
		Piece* pond2 = nullptr;

		Board board = Board();

		BoardPondTestFixture()
		{

			pond = new PondPiece(WHITE);
			pond2 = new PondPiece(BLACK);
			board.insert_piece({0, 700}, pond);
			board.insert_piece({ 100, 600 }, pond2);

		}

		~BoardPondTestFixture() {
			delete pond;
			delete pond2;
		};
	};

	BOOST_FIXTURE_TEST_SUITE(TestingBoardWithPond, BoardPondTestFixture)

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_Y_UP)
		{	
			



		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_Y_DOWN)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_X_RIGHT)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_X_LEFT)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_RIGHT_X_UP_Y)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_LEFT_X_DOWN_Y)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_LEFT_X_UP_Y)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_piece2_in_the_way_along_RIGHT_X_DOWN_Y)
		{




		}

		

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_different_Y_values_for_src_and_dest)
		{




		}

		BOOST_AUTO_TEST_CASE(Moving_piece1_with_different_Y_values_for_src_and_dest)
		{




		}

		BOOST_AUTO_TEST_CASE(find_piece)
		{




		}

		BOOST_AUTO_TEST_CASE(remove_piece)
		{




		}

		BOOST_AUTO_TEST_CASE(promote_pond_to_Queen)
		{




		}

		BOOST_AUTO_TEST_CASE(promote_pond_to_Rook)
		{




		}

		BOOST_AUTO_TEST_CASE(promote_pond_to_Bishop)
		{




		}

		BOOST_AUTO_TEST_CASE(promote_pond_to_Knight)
		{




		}



	BOOST_AUTO_TEST_SUITE_END()

}