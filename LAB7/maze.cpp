#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
Maze::Maze(std::string file){
    std::ifstream open_file(file);
    std::string txt;
    std::getline(open_file,txt,'\0');
    open_file.close();
    std::vector<Cell> tmp;
    int x = 0;
    int y = 0;
    for(int count = 0; count < txt.size(); count+=2){
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
        map_.push_back(tmp);
    }
    for(int i = map_.size() - 1; map_[i].size() == 0; i--){
        map_.pop_back();
    }
    dim_ = map_.size();
    for(int i = 0; i < dim_; i++){
        while(map_[i].size() < dim_) map_[i].push_back(Cell(' '));
    }
    fill_map();
}
Maze::Maze(std::string file, int dim)
:Maze(file)
{
    for(int i = dim_; i < dim; i++) map_.push_back(std::vector<Cell>());
    dim_ = dim;
    fill_map();
}
void Maze::fill_map(){
    for(int i = 0; i < dim_; i++){
        while(map_[i].size() < dim_) map_[i].push_back(Cell(' '));
    }
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