#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp> //single-header
#include <pond_piece.h>
#include <string>
using namespace chess;
namespace chess_tests {
    BOOST_AUTO_TEST_CASE(move_pond_forward)
    {
        std::string expected_value = "Bill";
        Piece* pond = new PondPiece(WHITE, POND, { 1,1});


        // assume MyClass is defined in MyClass.h
        // and get_value() has public accessibility
        BOOST_CHECK(pond->can_move(1,1) == true);
        delete pond;
    }
}
