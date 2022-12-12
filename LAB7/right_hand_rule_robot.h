#if !defined(right_hand_rule_robot_h)
#define right_hand_rule_robot_h
#include <iostream>
#include "maze.h"
#include "robot.h"
class RightHandRuleRobot : public Robot{
    public:
        RightHandRuleRobot():Robot(){}
        bool move(Maze& maze) override;
        Robot* clone_pointer() override;
        void rotate_left();
        void rotate_right();
    private:
        int direction_ = 0;
};
const std::vector<int> direction_to_offset(int dir);
#endif // right_hand_rule_robot_h
