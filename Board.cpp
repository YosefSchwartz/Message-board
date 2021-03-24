#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include <vector>
using namespace std;

#define RESET_VALUE 0

namespace ariel {
            Board::Board(){
                this->minV = RESET_VALUE; 
                this->minH = RESET_VALUE;
                this->maxV = RESET_VALUE;
                this->maxH = RESET_VALUE;
            }
            void Board::post (unsigned introw, unsigned intcol, Direction direction, string data){
                cout <<"POST"<< endl;
            }
            string Board::read (unsigned int row, unsigned int col, Direction direction, int length){
                return "READ";
            }
            void Board::show(){
                cout <<"SHOW"<< endl;
            }
}
