#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "maze.h"
#include "robot.h"
#include "pathfinder_robot.h"

PathfinderRobot::PathfinderRobot(const Maze& maze)
:Robot()
{   
    moves_.push({-2,-2});
    std::vector<bool> tmp;
    for(int y = 0; y < maze.size_y(); y++){
        tmp = std::vector<bool>();
        for(int x= 0; x < maze.size_x(); x++){
            tmp.push_back(!maze.is_wall(x,y));
        }
        dummy_.push_back(tmp);
    }
}
bool PathfinderRobot::move(Maze& maze){
    const int index = maze.find_robot(serial());
    const Maze::RobPos pos = maze.get_robot(index);
    MoveDir prev_move = moves_.top();
    MoveDir move;
    while(move.y_ != 2 and (!is_passable(pos.x_ + move.x_,pos.y_ + move.y_) or prev_move == move)){
        next_move_dir(move);
    }
    if(move.y_ == 2){
        if(maze.move(index,prev_move.x_,prev_move.y_)){
            dummy_[pos.y_][pos.x_] = false;
            moves_.pop();
            //std::cout<<dummy_<<std::endl; //uncomment to track checked cells
            return true;
        }
        return false;
    }
    if(maze.move(index,move.x_,move.y_)){
        negate(move);
        dummy_[pos.y_][pos.x_] = false;
        moves_.push(move);
        //std::cout<<dummy_<<std::endl; //uncomment to track checked cells 
        return true;
    }
    return false;
}
Robot* PathfinderRobot::clone_pointer() const{
    PathfinderRobot* tmp = new PathfinderRobot;
    tmp->set_serial(serial());
    tmp->dummy_ = dummy_;
    tmp->moves_ = moves_;
    return tmp;
}
bool PathfinderRobot::MoveDir::operator==(const MoveDir& mov){
    return x_ == mov.x_ and y_ == mov.y_;
}
bool PathfinderRobot::is_passable(int x, int y) const{
    if(x < 0 or y < 0 or x >= dummy_[0].size() or y >= dummy_.size()) return false;
    return dummy_[y][x];
}
void PathfinderRobot::next_move_dir(PathfinderRobot::MoveDir& mov){
    mov.x_++;
    if(mov.x_ == 2){
        mov.x_ = -1;
        mov.y_++;
    }
    if(!mov.y_ and !mov.x_) mov.x_++;
}
void PathfinderRobot::negate(MoveDir& mov){
    mov.x_ = -mov.x_;
    mov.y_ = -mov.y_;
}
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<bool>>& map){
    std::string spacer = "+";
    std::string block = "|";
    for(int i = 0; i < map[0].size() + 2; i++){
        spacer += "---+";
        block += "\u2588\u2588\u2588|";
    }
    os << spacer << std::endl << block << std::endl << spacer << std::endl;
    for(int y = 0; y < map.size(); y++){
        os << "|\u2588\u2588\u2588";
        for(int x = 0; x < map[0].size(); x++){
            if(map[y][x]){
                os << "|   "; 
            } else {
                os << "|\u2588\u2588\u2588";
            }
        }
        os << "|\u2588\u2588\u2588|" <<std::endl<< spacer << std::endl;
    }
    os<<block<<std::endl<<spacer<<std::endl;
    return os;
}