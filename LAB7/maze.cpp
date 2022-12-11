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
                robots_.push_back(RobPos(x,y));
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
    for(int i = 0; i < size_; i++){
        while(map_[i].size() < size_) map_[i].push_back(Cell(' '));
    }
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
    if(num < 1) throw std::invalid_argument("Invalid robot index");
    if(!x_offset and !y_offset) return false;
    RobPos pre_move_pos = robots_[num - 1];
    RobPos post_move_pos(pre_move_pos.x_ + x_offset,pre_move_pos.y_ + y_offset);
    post_move_pos.serial_ = pre_move_pos.serial_;
    if(is_exit(post_move_pos.x_,post_move_pos.y_)){
        map_[pre_move_pos.y_][pre_move_pos.x_] = Cell(' ');
        robots_.erase(robots_.begin() + num - 1);
        return true;
    }
    if(!is_empty(post_move_pos.x_,post_move_pos.y_)) return false;
    map_[pre_move_pos.y_][pre_move_pos.x_] = Cell(' ');
    map_[post_move_pos.y_][post_move_pos.x_] = Cell('R');
    robots_[num - 1] = post_move_pos;
    return true;
}
int Maze::find_robot(int serial) const{
    for(int i = 0; i < robots_.size(); i++){
        if(robots_[i].serial_ == serial) return i + 1;
    }
    return -1;
}
/*
        1
       -1
  4 -1  R  1 2
        1
        3
*/
const std::vector<bool> Maze::wall_pos(int x, int y) const{
    return {is_wall(x,y - 1),is_wall(x + 1 ,y),is_wall(x,y + 1),is_wall(x - 1,y)};
}
bool Maze::is_exit(int x, int y) const {
    if(!in_range(x,y)) return false;
    return map_[y][x].exit_;
    }
bool Maze::is_wall(int x, int y) const {
    if(!in_range(x,y)) return true;
    return map_[y][x].wall_;
    }
bool Maze::is_robot(int x, int y) const {
    if(!in_range(x,y)) return false;
    return map_[y][x].robot_;
    }
bool Maze::is_empty(int x, int y) const {
    if(!in_range(x,y)) return false;
    return !(map_[y][x].exit_ or map_[y][x].robot_ or map_[y][x].wall_);
    }
void Maze::make_wall_cell(int x, int y){
    if(!in_range(x,y)) throw std::invalid_argument("Invalid coordinates");
    map_[y][x] = Cell('*');
}
void Maze::make_empty_cell(int x, int y){
    if(!in_range(x,y)) throw std::invalid_argument("Invalid coordinates");
    map_[y][x] = Cell(' ');
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
    std::string spacer = "+";
    std::string block = "|";
    for(int i = 0; i < val.size() + 2; i++){
        spacer += "---+";
        block += "\u2588\u2588\u2588|";
    }
    os << spacer << std::endl << block << std::endl << spacer << std::endl;
    for(int y = 0; y < val.size(); y++){
        os << "|\u2588\u2588\u2588";
        for(int x = 0; x < val.size(); x++){
            if(!val.map_[y][x].wall_){
                os << "| " << val.map_[y][x] << " "; 
            } else {
                os << "|\u2588\u2588\u2588";
            }
        }
        os << "|\u2588\u2588\u2588|" <<std::endl<< spacer << std::endl;
    }
    os<<block<<std::endl<<spacer<<std::endl;
    return os;
}