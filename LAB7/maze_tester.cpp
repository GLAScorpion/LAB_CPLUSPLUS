#include <iostream>
#include "maze.h"
using namespace std;
int main()
{
   Maze maze("maze.txt");
   cout << maze << maze.size()<<endl;
}
