#include <iostream>
#include <random>
#include "maze.h"
#include "right_hand_rule_robot.h"
bool RightHandRuleRobot::move(Maze& maze){
    const int index = maze.find_robot(serial());
    const Maze::RobPos pos = maze.get_robot(index);
    const std::vector<bool> walls = maze.wall_pos(pos.x_,pos.y_);
    if(!direction_){
        int i = 0;
        direction_ = 4;
        for(; i < walls.size() and !walls[i]; i++){
            rotate_right();
        }
        if(i == walls.size()){
            std::random_device rand_dir;
            std::uniform_int_distribution<int> dir (1,4);
            direction_ = dir(rand_dir);
            std::vector<int> offset = direction_to_offset(direction_);
            direction_ = 0;
            return maze.move(index,offset[0], offset[1]);
        }
    }
    std::vector<int> dir_offset = direction_to_offset(direction_);
    rotate_right();
    std::vector<int> prev_wall_pos = direction_to_offset(direction_);
    if(!maze.is_wall(pos.x_ + prev_wall_pos[0] + dir_offset[0], pos.y_ + prev_wall_pos[1] + dir_offset[1])){
        return maze.move(index, prev_wall_pos[0] + dir_offset[0], prev_wall_pos[1] + dir_offset[1]);
    }
    rotate_left();
    if(!maze.is_wall(pos.x_ + dir_offset[0], pos.y_ + dir_offset[1])){
        return maze.move(index, dir_offset[0], dir_offset[1]);
    }
    rotate_left();
    return true;
}
Robot* RightHandRuleRobot::clone_pointer() const{
    RightHandRuleRobot* tmp = new RightHandRuleRobot;
    tmp->set_serial(serial());
    tmp->direction_ = direction_;
    return tmp;
}
void RightHandRuleRobot::rotate_left(){
    direction_--;
    if(!direction_) direction_ = 4;
}
void RightHandRuleRobot::rotate_right(){
    direction_++;
    if(direction_ == 5) direction_ = 1;
}
const std::vector<int> direction_to_offset(int dir){
    std::vector<int> offset(2); //x,y
    switch (dir)
    {
    case 1:
        offset[0] = 0;
        offset[1] = -1;
        break;
    case 2:
        offset[0] = 1;
        offset[1] = 0;
        break;
    case 3:
        offset[0] = 0;
        offset[1] = 1;
        break;
    case 4:
        offset[0] = -1;
        offset[1] = 0;
        break;
    default:
        throw std::invalid_argument("Uknown direction");
        break;
    }
    return offset;
}