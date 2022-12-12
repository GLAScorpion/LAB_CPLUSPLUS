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
    std::vector<MoveDir> init;
    moves_.push(init);
    std::vector<bool> tmp;
    for(int y = 0; y < maze.size(); y++){
        tmp = std::vector<bool>();
        for(int x= 0; x < maze.size(); x++){
            tmp.push_back(!maze.is_wall(x,y));
        }
        dummy_.push_back(tmp);
    }
    
}
bool PathfinderRobot::move(Maze& maze){
    const int index = maze.find_robot(serial());
    const Maze::RobPos pos = maze.get_robot(index);
    std::vector<MoveDir>& skip = moves_.top();
    MoveDir move;
    while(move.y_ != 2 and (!is_passable(pos.x_ + move.x_,pos.y_ + move.y_) or find(skip.begin(),skip.end(),move) != skip.end())){
        next_move_dir(move);
    }
    if(move.y_ == 2){
        move = skip[0];
        if(maze.move(index,move.x_,move.y_)){
            moves_.pop();
            return true;
        }
        return false;
    }
    if(maze.move(index,move.x_,move.y_)){
        skip.push_back(move);
        negate(move);
        std::vector<MoveDir> new_moves{move};
        dummy_[pos.y_][pos.x_] = false;
        moves_.push(new_moves);
        return true;
    }
    return false;
}
bool PathfinderRobot::MoveDir::operator==(const MoveDir& mov){
    return x_ == mov.x_ and y_ == mov.y_;
}
bool PathfinderRobot::is_passable(int x, int y){
    if(x < 0 or y < 0 or x >= dummy_.size() or y >= dummy_.size()) return false;
    return dummy_[y][x];
}
void PathfinderRobot::next_move_dir(PathfinderRobot::MoveDir& mov){
    mov.x_++;
    if(mov.x_ == 2){
        mov.x_ = -1;
        mov.y_++;
    }
    if(!mov.y_ and !mov.x_) mov.y_++;
}
void PathfinderRobot::negate(MoveDir& mov){
    mov.x_ = -mov.x_;
    mov.y_ = -mov.y_;
}