#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

#include<pond_piece.h>
using namespace chess;
namespace pond_tests {
	BOOST_AUTO_TEST_CASE(pond_move_forward_by_one)
	{
		Piece* pond = new PondPiece(WHITE, { 0, 700 });

		BOOST_TEST(pond->can_move(0, 600) == true);
		delete pond;

	}
	BOOST_AUTO_TEST_CASE(pond_move_forward_by_two)
	{
		Piece* pond = new PondPiece(WHITE,  { 0, 700 });

		BOOST_TEST(pond->can_move(0, 500) == true);
		delete pond;
	
	}
	BOOST_AUTO_TEST_CASE(pond_move_forward_by_one_then_two)
	{
		Piece* pond = new PondPiece(WHITE, { 0, 700 });

		BOOST_TEST(pond->can_move(0, 600) == true);
		pond->update_position(0, 600);
		BOOST_TEST(pond->can_move(0, 400) == false);
		delete pond;

	}
	BOOST_AUTO_TEST_CASE(pond_move_diagnol_by_one_right)
	{
		Piece* pond = new PondPiece(WHITE, { 0, 700 });

		BOOST_TEST(pond->can_move(100, 600) == true);
		delete pond;

	}
	BOOST_AUTO_TEST_CASE(pond_move_diagnol_by_one_left)
	{
		Piece* pond = new PondPiece(WHITE, { 100, 700 });

		BOOST_TEST(pond->can_move(0, 600) == true);
		delete pond;

	}
	BOOST_AUTO_TEST_CASE(pond_move_diagnol_by_one_off_board_left)
	{
		Piece* pond = new PondPiece(WHITE, { 0, 700 });

		BOOST_TEST(pond->can_move(-100, 600) == false);
		delete pond;

	}
	BOOST_AUTO_TEST_CASE(pond_move_diagnol_by_one_off_board_right)
	{
		Piece* pond = new PondPiece(WHITE, { 700, 700 });

		BOOST_TEST(pond->can_move(800, 600) == false);
		delete pond;

	}

	BOOST_AUTO_TEST_CASE(pond_move_backwards)
	{
		Piece* pond = new PondPiece(WHITE, { 0, 700 });
		BOOST_TEST(pond->can_move(0, 800) == false);
		delete pond;

	}
	/*BOOST_AUTO_TEST_CASE(pond_reaches_other_side)
	{
		Piece* pond = new PondPiece(WHITE, { 0, 100 });
		BOOST_TEST(pond->can_move(0, 500) == true);
		delete pond;

	}*/
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