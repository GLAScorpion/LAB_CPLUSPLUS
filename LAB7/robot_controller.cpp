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