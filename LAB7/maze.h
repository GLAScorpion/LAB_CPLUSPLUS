#if !defined(maze_h)
#define maze_h
#include <iostream>
#include <vector>
class Maze{
    public:
        explicit Maze(std::string file);
        bool is_exit(int x, int y){return map_[x][y] == Cell::exit;}
        bool is_wall(int x, int y){return map_[x][y] == Cell::wall;}
        bool is_empty(int x, int y){return map_[x][y];}
        int size(){return dim_;}
        //void set_robot(const Robot r);
    private:
        enum Cell : bool{ empty = true , wall = false, exit = false, robot = false};
        std::vector<std::vector<Cell>> map_;
        int dim_;
        int rob_x_;
        int rob_y_;
};


#endif // maze_h
