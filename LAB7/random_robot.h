#if !defined(random_robot_h)
#define random_robot_h
#include <iostream>
#include "robot.h"
class RandomRobot : public Robot{
    public:
    RandomRobot():Robot(){}
    bool move(Maze& maze) override;
    Robot* clone_pointer() const override;
};
#endif // random_robot_h
