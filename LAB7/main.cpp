#include <iostream>
#include <time.h>
#include <unistd.h>
#include "maze.h"
#include "robot_collection.h"
using namespace std;
int main(){
    Robot* rob;
    Maze maze("maze.txt");
    cout << maze <<endl<<"Quale robot inizializzare? (random o right_hand o pathfinder)\n";
    std::string answer;
    bool cicle = false;
    do{
        cicle = false;
        cin >> answer;
        if(answer == "random"){
            rob = new RandomRobot;
        }else if(answer == "right_hand"){
            rob = new RightHandRuleRobot;
        }else if(answer == "pathfinder"){
            rob = new PathfinderRobot(maze);
        }else{
            cout<<"Unknown answer, retry\n";
            cicle = true;
        }
    }while(cicle);
    maze.set_robot(1,rob->serial());
    int count = 0;
    while(maze.find_robot(rob->serial())!= -1){
        while(!rob->move(maze));
        cout<<maze << endl;
        timespec wait;
        wait.tv_nsec = 300000000;
        timespec t_remain;
        nanosleep(&wait,&t_remain);
        //sleep(1);
        count++;
    }
    cout << count <<endl;
}