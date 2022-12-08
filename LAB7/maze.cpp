#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
Maze::Maze(const std::string& file){
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
            if(txt[count + x] == 'S'){
                robots_.push_back(coord(x,y));
            }
        }
        y++;
        count += x;
        map_.push_back(tmp);
    }
    for(int i = map_.size() - 1; map_[i].size() == 0; i--){
        map_.pop_back();
    }
    size_ = map_.size();
    fill_map();
}
Maze::Maze(const std::string& file, int dim)
:Maze(file)
{
    for(int i = size_; i < dim; i++) map_.push_back(std::vector<Cell>());
    size_ = dim;
    fill_map();
}
Maze::Cell::Cell(const char& val){
    if(val == 'E'){
        exit_ = true;
    }else if(val == '*'){
        wall_ = true;
    }else if(val == 'S' or val == 'R'){
        robot_ = true;
    }else if(val != ' '){
        throw std::invalid_argument("Invalid cell value");
    }
}
bool Maze::move(int num, int x_offset, int y_offset){
    coord pre_move_pos = robots_[num - 1];
    coord post_move_pos(pre_move_pos.x_ + x_offset,pre_move_pos.y_ + y_offset);
    if(!is_empty(post_move_pos.x_,post_move_pos.y_)) return false;
    map_[pre_move_pos.y_][pre_move_pos.x_] = Cell(' ');
    map_[post_move_pos.y_][post_move_pos.x_] = Cell('R');
    robots_[num - 1] = post_move_pos;
    return true;
}
void Maze::fill_map(){
    for(int i = 0; i < size_; i++){
        while(map_[i].size() < size_) map_[i].push_back(Cell(' '));
    }
}
std::ostream& operator<<(std::ostream& os, const Maze::Cell& val){
    if(val.exit_){
        return os<<"E";
    }else if(val.robot_){
        return os<<"R";
    }else if(val.wall_){
        return os<<"*";
    }
    return os <<" ";
}
std::ostream& operator<<(std::ostream& os, const std::vector<Maze::Cell>& vec){
    for(int i = 0; i < vec.size(); i++){
        os << vec[i];
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Maze& val){
    for(int i = 0; i < val.size_ ; i++){
        os<<val.map_[i]<<std::endl;
    }
    return os;
}