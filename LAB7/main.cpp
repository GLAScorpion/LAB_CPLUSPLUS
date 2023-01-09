#include <iostream>
#include <time.h>
#include <unistd.h>
#include "maze.h"
#include "robot_collection.h"
using namespace std;
int main(){
    Robot* rob;
    std::string answer;
    cout<<"Scrivi il nome del file contenente il labirinto (con estensione)\n";
    cin>>answer;
    //Maze maze("big_maze.txt");
    //Maze maze("maze.txt");
    //Maze maze("ultra_maze.txt");
    Maze maze(answer);
    cout << maze <<endl<<"Quale robot inizializzare? (random o right_hand o pathfinder)\n";
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
        system("clear");
        cout<<maze << endl;
        timespec wait;
        wait.tv_nsec = 50000000;
        timespec t_remain;
        nanosleep(&wait,&t_remain);
        //sleep(1);
        count++;
    }
    cout << "Mosse valide eseguite: "<< count <<endl;
}