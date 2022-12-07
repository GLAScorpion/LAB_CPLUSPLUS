#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
Maze::Maze(std::string file, int size)
{
    std::ifstream open_file(file);
    std::string line;
    int x = 0;
    int y = 0;
    while(!open_file.eof()){
        std::getline(open_file,line,'\n');
        std::vector<Cell> tmp;
        for(x = 0; line.begin()+x != line.end(); x++){
            if(line[x] == 'E'){
                tmp.push_back(Cell::exit);
            }else if(line[x] == '*'){
                tmp.push_back(Cell::wall);
            }else if(line[x] == 'S'){
                rob_x_ = x;
                rob_y_ = y;
                tmp.push_back(Cell::robot);
            }else{
                tmp.push_back(Cell::empty);
            }
        }
        std::cout << tmp << std::endl;
        x = 0;
        y++;
    }
    dim_ = y;
    open_file.close();
}
std::ostream& operator<<(std::ostream& os, std::vector<Maze::Cell> vec){
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
    }
    return os;
}
std::ostream& Maze::operator<<(std::ostream& os, Maze::Cell val){
    if(val == empty){
        return os<<" ";
    }else if(val == Cell::exit){
        return os<<"E";
    }else if(val == Cell::robot){
        return os<<"R";
    }
    return os <<"*";
}