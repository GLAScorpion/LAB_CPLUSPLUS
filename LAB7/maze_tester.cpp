#include <iostream>
#include "maze.h"
using namespace std;
int main()
{
   Maze maze("maze.txt");
   cout << maze << maze.size_y()<<"x"<<maze.size_x()<<endl;
   Maze big_maze("big_maze.txt");
   cout << big_maze << big_maze.size_y()<<"x"<<big_maze.size_x()<<endl;
}
