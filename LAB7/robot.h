#if !defined(robot_h)
#define robot_h
#include <iostream>
#include "maze.h"
#include <random>
/*
     -1   0   1
-1    0   1   2
0     3   R   5
1     6   7   8

*/
class Robot{
    public:
        Robot()
        {
            static std::random_device rand_serial;
            static std::uniform_int_distribution<int> dist(0,INT32_MAX);
            serial_ = dist(rand_serial);
        }
        virtual bool move(Maze& maze) const = 0;
        int serial() const {return serial_;}
    private:
        int serial_;
};
#endif