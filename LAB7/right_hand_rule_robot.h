#if !defined(right_hand_rule_robot_h)
#define right_hand_rule_robot_h
#include <iostream>
#include "maze.h"
#include "robot.h"
class RightHandRuleRobot : public Robot{
    public:
        RightHandRuleRobot():Robot(){}
        bool move(Maze& maze) const override;
    private:
};
#endif // right_hand_rule_robot_h
