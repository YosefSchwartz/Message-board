#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    
    class Board {
        public:
            Board();
            void post (int row, int col, Direction direction, string data);
            string read (int row, int col, Direction direction, int length);
            void show();
    };
}
#endif