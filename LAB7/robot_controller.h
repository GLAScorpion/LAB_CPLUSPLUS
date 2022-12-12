#if !defined(robot_controller_h)
#define robot_controller_h
#include <iostream>
#include <vector>
#include "robot_collection.h"
#include "maze.h"
class RobotController{
    public:
        explicit RobotController(const std::string& filename);
        bool move(int num);
        bool move_all(); 
        void set_robot(Robot* robot, int num);
        int find_robot(int serial) const;
        friend std::ostream& operator<<(std::ostream& os, const RobotController& controller);
        int get_robot_count() const {return robots_.size();}
        int get_robot_serial(int num) const {return robots_.at(num - 1)->serial();}
    private:
        Maze maze_;
        std::vector<Robot*> robots_;
};
#endif // robot_controller_h
