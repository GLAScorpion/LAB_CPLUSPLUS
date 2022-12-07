#include "maze.h"
#include <iostream>
#include <fstream>
Maze::Maze(std::string file)
{
    if(dim_<2) throw std::invalid_argument("Invalid maze size");
    std::fstream open_file(file,std::ios::in);
    char* value;
    int x = 0;
    int y = 0;
    while(open_file >> value){
        if(value == "\n"){
            y++;
            x = 0;
        }else{
            if(value == "E"){
                map_[x][y] = Cell::exit;
            }else if(value == "*"){
                map_[x][y] = Cell::wall;
            }else if(value == "R"){
                rob_x_ = x;
                rob_y_ = y;
                map_[x][y] = Cell::robot;
            }else{
                map_[x][y] = Cell::empty;
            }
            x++;
        }
    }
    open_file.close();
}