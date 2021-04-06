#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include <map>
#include <limits>
#include <fstream>
#include <ctime>
using namespace std;

#define RESET_VALUE -1

namespace ariel {
    Board::Board(){
        map<unsigned int,map<unsigned int, char>> b;
        unsigned int minH = numeric_limits<unsigned int>::max();
        unsigned int minV = numeric_limits<unsigned int>::max();
        unsigned int maxX = numeric_limits<unsigned int>::min();
        unsigned int maxY = numeric_limits<unsigned int>::min();
    }

    void Board::updateLimitsH(unsigned int r, unsigned int c, unsigned int l){
        if(r<minV) this->minV=r;
        if(r>maxV) this->maxV=r;
        if(c<minH) this->minH=c;
        if(c+l>maxH) this->maxH=c+l;
    }
    void Board::updateLimitsV(unsigned int r, unsigned int c, unsigned int l){
        if(r<minV) minV=r;
        if(r+l>maxV) maxV=r+l;
        if(c<minH) minH=c;
        if(c>maxH) maxH=c;
    }
    void Board::post (unsigned int row, unsigned int col, Direction direction, string data){
        switch (direction)
        {
            case Direction::Vertical:{
                updateLimitsV(row,col,data.length());
                unsigned int j = 0;
                for(unsigned int i=row;i<row+data.length();i++){
                    b[i][col]= data[j];
                    j++;
                }
                break;
            }
            case Direction::Horizontal:{
                updateLimitsH(row,col,data.length());
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
            string msg = "";
            switch (direction)
            {
            case Direction::Vertical:
                for(unsigned int i=row;i<row+length;i++){
                    char c = b[i][col];
                    if (int(c)== 0)
                        c='_';
                    msg+= c;
                }
                break;
                
            case Direction::Horizontal:
                for(unsigned int i=col;i<col+length;i++){
                    char c = b[row][i];
                    if (int(c)==0)
                        c='_';
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
        tm *ltm = localtime(&now);
        string day = to_string(ltm->tm_mday);
        string month = to_string(ltm->tm_mon);
        string year = to_string(1900 + ltm->tm_year);
        string time = to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
        string file_name = "Board_"+day+"."+month+"."+year+"_"+time+".txt";
        ofstream board(file_name);
        for(unsigned int i = minV; i<maxV;i++){
            // board<<"#"<<i<<"\t\t\t\t";
            for(unsigned int j=minH;j<maxH;j++){
                char c = b[i][j];
                if(c==0) c='_';
                board<<c;
            }
            board<<endl;
        }
    }
}
