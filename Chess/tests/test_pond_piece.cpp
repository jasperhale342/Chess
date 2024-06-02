#include <boost/test/unit_test.hpp>
#include "pond_piece.h"

using namespace chess;
// not sure if this should be allocated dynamically. Since the program is dynamically allocating memory for each pieces 
// I guess it would make sense to also test that way
namespace tests_pond {
	struct PondTestFixture
	{
		Piece* pond = nullptr;

		PondTestFixture()

		{
			pond = new PondPiece(WHITE);
		}

		~PondTestFixture() { delete pond; };
	};

	BOOST_FIXTURE_TEST_SUITE(TestingPond, PondTestFixture)

		BOOST_AUTO_TEST_CASE(pond_move_forward_by_one)
	{
		BOOST_TEST(pond->can_move({ 0, 700 }, { 0,600 }) == true);

	}

	BOOST_AUTO_TEST_CASE(pond_move_forward_by_two)
	{


		BOOST_TEST(pond->can_move({ 0, 700 }, { 0, 500 }) == true);


	}

	BOOST_AUTO_TEST_CASE(pond_move_forward_by_one_then_two)
	{


		BOOST_TEST(pond->can_move({ 0, 700 }, { 0, 600 }) == true);
		BOOST_TEST(pond->can_move({ 0, 600 }, { 0, 400 }) == false);


	}
	BOOST_AUTO_TEST_CASE(pond_move_diagnol_by_one_right)
	{


		BOOST_TEST(pond->can_move({ 0, 700 }, { 100, 600 }) == true);


	}
	BOOST_AUTO_TEST_CASE(pond_move_diagnol_by_one_left)
	{


		BOOST_TEST(pond->can_move({ 100, 700 }, { 0, 600 }) == true);


	}
	BOOST_AUTO_TEST_CASE(move_pond_by_1_to_the_left_off_the_board)
	{


		BOOST_TEST(pond->can_move({ 0, 700 }, { -100, 600 }) == false);


	}
	BOOST_AUTO_TEST_CASE(move_pond_by_1_to_the_right_off_the_board)
	{


		BOOST_TEST(pond->can_move({700, 600}, { 800, 600 }) == false);


	}

	BOOST_AUTO_TEST_CASE(pond_move_backwards)
	{

		BOOST_TEST(pond->can_move({ 0, 700 }, { 0, 800 }) == false);


	}

	BOOST_AUTO_TEST_CASE(pond_move_left)
	{

		BOOST_TEST(pond->can_move({ 200, 700 }, { 100, 700 }) == false);


	}


	BOOST_AUTO_TEST_CASE(pond_move_right)
	{

		BOOST_TEST(pond->can_move({ 0, 700 }, { 100, 700 }) == false);


	}


	BOOST_AUTO_TEST_SUITE_END()
}

// move forward by 1 sqaure, piece in the way
// move forward by 1 sqaure, no piece in the way
// move forward by 2 sqaures, piece in the way
// move forward by 2 sqaures, no piece in the way
// en passant
// capture piece of different color
// fail to capture piece of same color 
// cant move forward when piece is in the way
// cant move backwards
// can only move forward 