#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "maze.h"
#include "robot.h"
#include "pathfinder_robot.h"
PathfinderRobot::PathfinderRobot()
:Robot()
{
    std::vector<MoveDir> init;
    moves_.push(init);
}
bool PathfinderRobot::move(Maze& maze){
    const int index = maze.find_robot(serial());
    const Maze::RobPos pos = maze.get_robot(index);
    if(!dummy_.size()) {
        dummy_ = maze;
        dummy_.make_empty_cell(pos.x_,pos.y_);
    }
    std::vector<MoveDir>& skip = moves_.top();
    MoveDir move;
    while(move.y_ != 2 and (maze.is_wall(pos.x_ + move.x_, pos.y_ + move.y_) or find(skip.begin(),skip.end(),move) != skip.end())){
        next_move_dir(move);
        //std::cout<<move.y_<<" "<<move.x_<<maze.is_wall(pos.x_ + move.x_, pos.y_ + move.y_)<<std::endl;
    }
    //std::cin.get();
    if(move.y_ == 2){
        //std::cout<<"flag\n";
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
        moves_.push(new_moves);
        return true;
    }
    return false;
}
bool PathfinderRobot::MoveDir::operator==(const MoveDir& mov){
    return x_ == mov.x_ and y_ == mov.y_;
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
/*
MoveDir move = {-1,-1};
    std::vector<MoveDir> prev_move;
    std::vector<MoveDir> skip;
    if(moves_.size()){ 
        skip = moves_.top();
        if(last_back.x_ or last_back.y_){
            skip.push_back(last_back);
            moves_.pop();
            moves_.push(skip);
            last_back = {0,0};
        }
    }
    while(!maze.is_empty(pos.x_ + move.x_,pos.y_ + move.y_) and move.y_!=2 or std::find(skip.begin(),skip.end(),move) != skip.end()){
       next_move_dir(move);
    }  
    int y = move.x_;
    int x = move.y_;     
    if(move.y_ == 2){
        prev_move = moves_.top();
        moves_.pop();
        
    }
    if(moves_.size()==0){
        moves_.push({x,y});
        return maze.move(index,x,y);
    }
    if(prev_move[0] == x and prev_move[1] == y){
        last_back = prev_move;
        moves_.pop();
        return maze.move(index,x,y);
    }
    moves_.push({x,y});
    return maze.move(index,x,y);
*/