#if !defined(robot_controller_h)
#define robot_controller_h
#include <iostream>
#include <vector>
#include "robot_collection.h"
#include "maze.h"
class RobotController{
    public:
        explicit RobotController(const std::string& filename);
        bool move(int index);
        bool move_all(); 
    private:
        Maze maze_;
        std::vector<DummyBot*> robots_;
};
#endif // robot_controller_h
