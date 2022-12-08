#include <iostream>
#include <time.h>
#include "maze.h"
#include "random_robot.h"
using namespace std;
int main(){
    Maze maze("maze.txt");
    cout << maze <<endl;
    RandomRobot rand_rob;
    maze.set_robot(1,rand_rob.serial());
    int count = 0;
    while(maze.find_robot(rand_rob.serial())!= -1){
        while(!rand_rob.move(maze));
        cout<<maze << endl;
        timespec wait;
        wait.tv_nsec = 50000000;
        timespec t_remain;
        nanosleep(&wait,&t_remain);
        //sleep(1);
        count++;
    }
    cout << count <<endl;
}