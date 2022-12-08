#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
/*
Maze::Maze(std::string file)
{
    std::ifstream open_file(file);
    std::string line;
    std::vector<Cell> tmp;
    int x = 0;
    int y = 0;
    while(!open_file.eof()){
        std::getline(open_file,line,'\n');
        tmp = std::vector<Cell>();
        for(x = 0; x < static_cast<int>(line.size()-1); x++){
            tmp.push_back(Cell(line[x]));
            if(line[x] == 'S'){
                rob_x_ = x;
                rob_y_ = y;
            }
        }
        if(tmp.size()>0) map_.push_back(tmp);
        y++;
    }
    std::getline(open_file,line,'\0');
    tmp = std::vector<Cell>();
    for(x = 0; x < static_cast<int>(line.size()-1); x++){
        tmp.push_back(Cell(line[x]));
        if(line[x] == 'S'){
            rob_x_ = x;
            rob_y_ = y;
        }
    }
    if(tmp.size()>0) map_.push_back(tmp);
    open_file.close();
    dim_ = map_.size();
}
*/
Maze::Maze(std::string file){
    std::ifstream open_file(file);
    std::string txt;
    std::getline(open_file,txt,'\0');
    open_file.close();
    std::vector<Cell> tmp;
    int x = 0;
    int y = 0;
    for(int count = 0; count < txt.size(); count++){
        tmp = std::vector<Cell>();
        for(x = 0; isprint(txt[x + count]) and count < txt.size(); x++){
            tmp.push_back(Cell(txt[x + count]));
            if(txt[count] == 'S'){
                rob_x_ = x;
                rob_y_ = y;
            }
        }
        y++;
        count += x;
        if(tmp.size()>0) map_.push_back(tmp);
    }
    dim_ = map_.size();
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
    for(int i = 0; i < val.dim_ ; i++){
        os<<val.map_[i]<<std::endl;
    }
    return os;
}