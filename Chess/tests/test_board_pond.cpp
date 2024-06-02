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
			board.insert_piece({ 0, 700 }, pond);
			board.insert_piece({ 100, 600 }, pond2);

		}

		~BoardPondTestFixture() {
			delete pond;
			delete pond2;
		};
	};

BOOST_FIXTURE_TEST_SUITE(TestingBoardWithPond, BoardPondTestFixture)

	BOOST_AUTO_TEST_CASE(Pond_taking_right)
	{
		board.if_able_to_move_piece_then_move_piece({ 0, 700 }, { 100, 600 }, pond);
		
		
	}

	BOOST_AUTO_TEST_CASE(Pond_taking_left)
	{
		


	}

	BOOST_AUTO_TEST_CASE(Pond_moves_forward_by_2_with_another_piece_in_front_by_1)
	{



	}

	BOOST_AUTO_TEST_CASE(Pond_moves_forward_by_2_making_it_en_passantable)
	{



	}


	BOOST_AUTO_TEST_CASE(Pond_is_no_longer_en_passantable_on_next_turn)
	{



	}

	BOOST_AUTO_TEST_CASE(Pond_taking_by_en_passant_LEFT_on_en_passantable_pond)
	{



	}

	BOOST_AUTO_TEST_CASE(Pond_taking_by_en_passant_RIGHT_on_en_passantable_pond)
	{



	}


	BOOST_AUTO_TEST_CASE(Pond_taking_by_en_passant_RIGHT_on_NON_en_passantable_pond)
	{



	}

	BOOST_AUTO_TEST_CASE(Pond_taking_by_en_passant_LEFT_on_NON_en_passantable_pond)
	{



	}

	BOOST_AUTO_TEST_CASE(Pond_attempting_to_take_en_passant_on_a_NON_pond_piece)
	{



	}

	BOOST_AUTO_TEST_CASE(Promote_Pond)
	{



	}

BOOST_AUTO_TEST_SUITE_END()
}