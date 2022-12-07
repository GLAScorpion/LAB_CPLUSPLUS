#if !defined(maze_h)
#define maze_h
#include <iostream>
#include <vector>
class Maze{
    public:
        explicit Maze(std::string file, int size = 9);
        bool is_exit(int x, int y){return map_[x][y] == Cell::exit;}
        bool is_wall(int x, int y){return map_[x][y] == Cell::wall;}
        bool is_empty(int x, int y){return map_[x][y];}
        int size(){return dim_;}
        friend std::ostream& operator<<(std::ostream& os, Maze::Cell val);
        //void set_robot(const Robot r);
    private:
        struct Cell;
        std::vector<std::vector<Cell>> map_;
        int dim_;
        int rob_x_;
        int rob_y_;
};
std::ostream& operator<<(std::ostream& os, std::vector<Maze::Cell> vec);
std::ostream& operator<<(std::ostream& os, Maze val);
#endif // maze_h
