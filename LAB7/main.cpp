#include <iostream>
#include "maze.h"
#include "random_robot.h"
using namespace std;
int main(){
    Maze maze("maze.txt");
    cout << maze <<endl;
    RandomRobot rand_rob(1);
    rand_rob.move(maze);
    cout << maze << endl;
}