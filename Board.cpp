#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include <map>
#include <limits>
#include <fstream>
#include <ctime>
using namespace std;

namespace ariel {
    Board::Board(){
        map<unsigned int,map<unsigned int, char>> b;
    }

    void Board::post (unsigned int row, unsigned int col, Direction direction, string data){
        switch (direction)
        {
            case Direction::Vertical:{
                unsigned int j = 0;
                for(unsigned int i=row;i<row+data.length();i++){
                    b[i][col]= data[j];
                    j++;
                }
                break;
            }
            case Direction::Horizontal:{
                unsigned int k = 0;
                for(unsigned int i=col;i<col+data.length();i++){
                    b[row][i]= data[k];
                    k++;
                }
                break;
            } 
        }
    }
    string Board::read (unsigned int row, unsigned int col, Direction direction, unsigned int length){
            string msg;
            switch (direction)
            {
            case Direction::Vertical:
                for(unsigned int i=row;i<row+length;i++){
                    char c = b[i][col];
                    if(c == 0){
                        c ='_';
                    }
                    msg+= c;
                }
                break;
                
            case Direction::Horizontal:
                for(unsigned int i=col;i<col+length;i++){
                    char c = b[row][i];
                    if(c == 0){
                        c='_';
                    }
                    msg+= c;
                }
                break;

            default:
                break;
            }
            return msg;
        }
    void Board::show(){
        
        time_t now = time(0);
        const int startYear = 1900;
        tm *ltm = localtime(&now);
        string day = to_string(ltm->tm_mday);
        string month = to_string(ltm->tm_mon);
        string year = to_string(startYear + ltm->tm_year);
        string time = to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
        string file_name = "Board-"+day+"."+month+"."+year+"_"+time+".txt";
        ofstream board(file_name);

        for(unsigned int i = 0; i<Board::b.size();i++){
            for(unsigned int j=0;j<Board::b[i].size();j++){
                char c = b[i][j];
                if(c==0) {c='_';}
                board<<c;
            }
            board<<endl;
        }
    }
}
