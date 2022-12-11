#if !defined(pathfinder_robot_h)
#define pathfinder_robot_h
#include <iostream>
#include <stack>
#include <vector>
#include "maze.h"
#include "robot.h"
class PathfinderRobot : public Robot{
    public:
        PathfinderRobot():Robot(){}
        bool move(Maze& maze) override;
    private:
        struct MoveDir{
            int x_;
            int y_;
            MoveDir(int x, int y):x_{x},y_{y}{}
            MoveDir():x_{-2},y_{-2}{}
        };
        int move_index_ = 0;
        std::stack<std::vector<MoveDir>> moves_;
        MoveDir last_back = {0,0};
        void next_move_dir(MoveDir& mov);
};
#endif // pathfinder_robot_h
