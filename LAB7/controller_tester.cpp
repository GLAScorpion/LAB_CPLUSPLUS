#include <iostream>
#include "robot_collection.h"
#include "robot_controller.h"
#include <unistd.h>
#include <time.h>
using namespace std;
int main(){
    std::string filename = "maze2.txt";
    RobotController controller(filename);
    controller.set_robot(new RightHandRuleRobot,1);
    controller.set_robot(new RandomRobot,2);
    controller.set_robot(new RandomRobot,3);
    cout<<controller<<endl;
    cin.get();
    while(controller.get_robot_count()){
        controller.move_all();
        system("clear");
        cout<<controller<<endl;
        timespec wait;
        wait.tv_nsec = 70000000;
        timespec t_remain;
        nanosleep(&wait,&t_remain);
    }
}