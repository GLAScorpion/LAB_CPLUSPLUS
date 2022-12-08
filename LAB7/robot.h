#if !defined(robot_h)
#define robot_h
#include <iostream>
#include "maze.h"
/*
     -1   0   1
-1    0   1   2
0     3   R   5
1     6   7   8

*/
class Robot{
    public:
        Robot(int num):num_{num}{}
        virtual bool move(Maze& maze) const = 0;
        int num() const {return num_;}
    private:
        int num_;
};
#endif