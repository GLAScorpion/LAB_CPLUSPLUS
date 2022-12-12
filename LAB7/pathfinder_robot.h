#if !defined(pathfinder_robot_h)
#define pathfinder_robot_h
#include <iostream>
#include <stack>
#include <vector>
#include "maze.h"
#include "robot.h"
class PathfinderRobot : public Robot{
    public:
        PathfinderRobot(){};
        explicit PathfinderRobot(const Maze& maze);
        bool move(Maze& maze) override;
        Robot* clone_pointer() override;
    private:
        struct MoveDir{
            int x_;
            int y_;
            MoveDir(int x, int y):x_{x},y_{y}{}
            MoveDir():x_{-1},y_{-1}{}
            bool operator==(const MoveDir& mov);
        };
        bool is_passable(int x, int y);
        void next_move_dir(MoveDir& mov);
        void negate(MoveDir& mov);
        std::vector<std::vector<bool>> dummy_;
        std::stack<MoveDir> moves_;
};
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<bool>>& map);
#endif // pathfinder_robot_h
