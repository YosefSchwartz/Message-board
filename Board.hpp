#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    
    class Board {
        private:
            int minV;
            int minH;
            int maxV;
            int maxH;
            vector<vector<char>> b;
        public:
            Board();
            void post (unsigned int row, unsigned int col, Direction direction, string data);
            string read (unsigned int row, unsigned int col, Direction direction, int length);
            void show();
    };
}
#endif