#include <iostream>
#include <random>
#include "maze.h"
#include "right_hand_rule_robot.h"
bool RightHandRuleRobot::move(Maze& maze) const{
    std::random_device rand_x;
    std::random_device rand_y;
    std::uniform_int_distribution<int> dist(-1, 1);
    int x = 0;
    int y = 0;
    while(x == 0 and y == 0){
        x = dist(rand_x);
        y = dist(rand_y);
    }
    int pos = maze.find_robot(serial());
    return maze.move(pos, x, y );
}