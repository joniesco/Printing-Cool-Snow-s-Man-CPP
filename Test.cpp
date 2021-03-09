#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    /* Add more checks here */
    CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(33232124) == string("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
    CHECK(snowman(24313142) == string("  ___\n .....\n (O .)\n/(   )>\n (\" \")"));
    CHECK(snowman(11111111) == string(" _===_\n (.,.)\n<( : )>\n ( : )"));
    CHECK(snowman(22222222) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(33333333) == string("   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444333) == string("  ___\n (_*_)\n (- -)\n (> <)\\\n (___)"));



}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
    /* Add more checks here */
    CHECK(snowman(11114411) != string("       \n _===_ \n (.,.)"));
    CHECK(snowman(11114411)!=string("( : )")); 
    CHECK(snowman(11111111) != string("  \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222) != string("  ___  \n .... \n\\(o.o)/\n (] [) \n "));
    CHECK(snowman(33333333) != string("  (O_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444444) != string("  ___  \n (_*_) \n (  ) \n (   ) "));


}
TEST_CASE("Bad input") {
    CHECK_THROWS(snowman(51));  // not enough charac
    CHECK_THROWS(snowman(122223123211213)); // The input is to long
    CHECK_THROWS(snowman(12345678)); // some of the inputs are bigger than 4
    CHECK_THROWS(snowman(13000000)); // some of the inputs are smaller than 1
    CHECK_THROWS(snowman(-10202020)); //  the input is negative number
    CHECK_THROWS(snowman(-23124211)); // Can't receive a negative number
    CHECK_THROWS(snowman(1));//wrong input
    CHECK_THROWS(snowman(2));//wrong input
    CHECK_THROWS(snowman(3));//wrong input
    CHECK_THROWS(snowman(4));//wrong input
}