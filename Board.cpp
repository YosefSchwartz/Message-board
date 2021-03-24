#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include <vector>
using namespace std;

#define RESET_VALUE 0

namespace ariel {
            Board::Board(){
                int minV = RESET_VALUE; 
                int minH = RESET_VALUE;
                int maxV = RESET_VALUE;
                int maxH = RESET_VALUE;
                vector<vector<char>> b;
            }
            void Board::post (int row, int col, Direction direction, string data){
                cout <<"POST"<< endl;
            }
            string Board::read (int row, int col, Direction direction, int length){
                return "READ";
            }
            void Board::show(){
                cout <<"SHOW"<< endl;
            }
}
