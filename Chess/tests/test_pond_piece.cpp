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
		BOOST_TEST(true);
	}
	BOOST_AUTO_TEST_CASE(pond_move_forward_by_two)
	{
		Piece* pond = new PondPiece(WHITE,  { 0, 700 });

		BOOST_TEST(pond->can_move(0, 500) == true);
		delete pond;
		BOOST_TEST(true);
	}
	BOOST_AUTO_TEST_CASE(pond_reaches_other_side)
	{
		Piece* pond = new PondPiece(WHITE,  { 0, 700 });

		BOOST_TEST(pond->can_move(0, 500) == true);
		delete pond;
		BOOST_TEST(true);
	}
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