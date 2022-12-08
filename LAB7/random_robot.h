#if !defined(random_robot_h)
#define random_robot_h
#include <iostream>
#include "robot.h"
class RandomRobot : public Robot{
    public:
    explicit RandomRobot(int num):Robot(num){}
    bool move(Maze& maze) const override;
};
#endif // random_robot_h
