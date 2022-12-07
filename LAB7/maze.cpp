#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
Maze::Maze(std::string file)
{
    std::ifstream open_file(file);
    std::string line;
    std::string txt;
    std::getline(open_file, txt, '\0');
    std::cout<<line<<std::endl;
    int x = 0;
    int y = 0;
    bool loop = true;
    while(loop){
        if(open_file.eof()) loop = false;
        std::getline(open_file,line,'\n');
        std::vector<Cell> tmp;
        std::cout<<static_cast<int>(line.size())<<std::endl;
        for(x = 0; x < static_cast<int>(line.size()-1); x++){
            tmp.push_back(Cell(line[x]));
            if(line[x] == 'S'){
                rob_x_ = x;
                rob_y_ = y;
            }
        } 
        map_.push_back(tmp);
        y++;
    }
    open_file.close();
    dim_ = y-1;
}
Maze::Cell::Cell(const char& val){
    if(val == 'E'){
        exit_ = true;
    }else if(val == '*'){
        wall_ = true;
    }else if(val == 'S'){
        robot_ = true;
    }else if(val != ' '){
        throw std::invalid_argument("Invalid cell value");
    }
}
std::ostream& operator<<(std::ostream& os, Maze::Cell val){
    if(val.exit_){
        return os<<"E";
    }else if(val.robot_){
        return os<<"R";
    }else if(val.wall_){
        return os<<"*";
    }
    return os <<" ";
}
std::ostream& operator<<(std::ostream& os, std::vector<Maze::Cell> vec){
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, Maze val){
    for(int i = 0; i < val.dim_; i++){
        os<<val.map_[i]<<std::endl;
    }
    return os;
}