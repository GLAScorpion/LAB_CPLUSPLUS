#if !defined(pathfinder_robot_h)
#define pathfinder_robot_h
#include <iostream>
#include <stack>
#include <vector>
#include "maze.h"
#include "robot.h"
class PathfinderRobot : public Robot{
    public:
        PathfinderRobot();
        bool move(Maze& maze) override;
    private:
        struct MoveDir{
            int x_;
            int y_;
            MoveDir(int x, int y):x_{x},y_{y}{}
            MoveDir():x_{-1},y_{-1}{}
            bool operator==(const MoveDir& mov);
        };
        Maze dummy_;
        std::stack<std::vector<MoveDir>> moves_;
        void next_move_dir(MoveDir& mov);
        void negate(MoveDir& mov);
};
#endif // pathfinder_robot_h
