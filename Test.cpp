/**
 * Test to check snowman exam.
 * cpp course.
 *
 * AUTHORS: Yosef Schwartz.
 * 
 * Date: 08 on march 2021.
 */

#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
using namespace std;

//Vertical up-down
//Horizontal left-right

/*
  012345678901234567890123456789
0:______P_______________________
1:____$_u__\\\\\___T____________
2:____Bur Sonabcdefration now!__
3:____a_e__________y____________
4:____s_ __________ ____________
5:_Yosifl__________i____________
6:____c_o__________t____________
7:__re$oulution____!____________
8:______e_______________________
*/

Board* b = new Board();
void init(Board* b){
b->post(2,4,Direction::Horizontal, "Buy Sonyplaystation now!");
b->post(0,6,Direction::Vertical, "Pure love");
b->post(5,1,Direction::Horizontal, "Yosef");
b->post(2,11,Direction::Horizontal, "abcdefg");
b->post(1,7,Direction::Vertical, "Try it!");
b->post(7,2,Direction::Horizontal, "revoulution");
b->post(1,4,Direction::Vertical, "$Basic$");
b->post(1,9,Direction::Horizontal, "\\\\\\\\\\");
}



TEST_CASE("Read from the board") {
    CHECK((*b).read(2,4,Direction::Horizontal,12) == string("Bur Sonabcde"));
    CHECK((*b).read(3,2,Direction::Vertical,7) == string("__o_r__"));
    CHECK((*b).read(1,5,Direction::Vertical,5) == string("_u__f"));
    CHECK((*b).read(7,4,Direction::Horizontal,12) == string("$oulution___"));
    CHECK((*b).read(6,2,Direction::Horizontal,12) == string("__c_o_______"));
    CHECK((*b).read(1,10,Direction::Vertical,6) == string("\\n_____"));
    CHECK((*b).read(1,6,Direction::Vertical,3) == string("ure"));
    CHECK((*b).read(1,4,Direction::Horizontal,12) == string("$_u__\\\\\\\\\\__"));
    CHECK((*b).read(5,0,Direction::Horizontal,8) == string("_Yosifl_"));
    CHECK((*b).read(6,8,Direction::Horizontal,4) == string("____"));
    CHECK((*b).read(7,8,Direction::Vertical,12) == string("ution____!__"));
    CHECK((*b).read(2,4,Direction::Vertical,0) == string(""));
    CHECK((*b).read(0,29, Direction::Vertical,5) == string("_____"));
    CHECK((*b).read(1,3,Direction::Vertical,7) == string("____s_e"));
    CHECK((*b).read(3,4,Direction::Horizontal,12) == string("a_e_________"));

    SUBCASE("fail on length"){
      CHECK((*b).read(3,4,Direction::Horizontal,12) != string("a_e________"));
      CHECK((*b).read(2,4,Direction::Vertical,0) != string("s"));
      CHECK((*b).read(6,8,Direction::Horizontal,4) != string("_____"));
    }
    SUBCASE("fail on unequal"){
      CHECK((*b).read(5,0,Direction::Horizontal,8) == string("_Yoklfl_"));
      CHECK((*b).read(7,4,Direction::Horizontal,12) == string("$oomktion___"));
      CHECK((*b).read(1,5,Direction::Vertical,5) == string("_uj_f"));
    }
}

TEST_CASE("Post on the board"){
  SUBCASE("Horizontal"){
    //Will read line, post another string and read again
    std::string sBefore = (*b).read(5,0,Direction::Horizontal,8);
    (*b).post(5,2,Direction::Horizontal,"abc");
    std::string sAfter = (*b).read(5,0,Direction::Horizontal,8);
    CHECK((*b).read(5,2,Direction::Horizontal,3)=="abc");
    CHECK_NE(sBefore,sAfter);
    //Post the before string to reset
    (*b).post(5,0,Direction::Horizontal,sBefore);
  }
  SUBCASE("Vertical"){
    //Will read line, post another string and read again
    std::string sBefore = (*b).read(0,4,Direction::Vertical,9);
    (*b).post(5,4,Direction::Vertical,"abc");
    std::string sAfter = (*b).read(0,4,Direction::Vertical,9);
    CHECK((*b).read(5,4,Direction::Vertical,3)=="abc");
    CHECK_NE(sBefore,sAfter);
    //Post the before string to reset
    (*b).post(0,4,Direction::Vertical,sBefore);
  }
}