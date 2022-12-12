#include <iostream>
#include "robot_controller.h"
RobotController::RobotController(const std::string& filename)
:maze_{filename}
{   
    for(int i = 0; i < maze_.get_robot_count(); i++){
        robots_.push_back(new DummyBot);
    }
    for(int i = 0; i < robots_.size(); i++ ){
        maze_.set_robot(i + 1,robots_[i]->serial());
    }
}
bool RobotController::move(int num){
    if(robots_.at(num - 1)->move(maze_)){
        if(maze_.find_robot(robots_.at(num - 1)->serial()) == -1) robots_.erase(robots_.begin() + num - 1);
        return true;
    }
    return false;
}
bool RobotController::move_all(){
    bool res = false;
    for(int i = 0; i < robots_.size(); i++){
        if(move(i + 1)) res = true;
    }
    return true;
}
void RobotController::set_robot(Robot* robot, int num){
    if(num < 1 or num > robots_.size()) throw std::invalid_argument("Invalid robot number");
    robots_[num - 1] = robot;
    maze_.set_robot(num, robot->serial());
}
int RobotController::find_robot(int serial) const{
    for(int i = 0; i < robots_.size(); i++){
        if(robots_[i]->serial() == serial) return i + 1;
    }
    return -1;
}