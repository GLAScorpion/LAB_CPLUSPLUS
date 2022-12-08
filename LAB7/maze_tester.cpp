#include <iostream>
#include "maze.h"
using namespace std;
int main()
{
   Maze maze("maze.txt");
   cout << maze << maze.size()<<endl;
   Maze big_maze("maze.txt", 12);
   cout << big_maze << big_maze.size()<<endl;
}
