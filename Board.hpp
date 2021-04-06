#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;

namespace ariel{
    class Board {
        private:
            map<unsigned int,map<unsigned int, char>> b;
            unsigned int minV;
            unsigned int minH;
            unsigned int maxV;
            unsigned int maxH;

            void updateLimitsH(unsigned int r, unsigned int c, unsigned int l);
            void updateLimitsV(unsigned int r, unsigned int c, unsigned int l);
        public:
            Board();
            void post (unsigned int row, unsigned int col, Direction direction, string data);
            string read (unsigned int row, unsigned int col, Direction direction, unsigned int length);
            void show();
    };
}
#endif