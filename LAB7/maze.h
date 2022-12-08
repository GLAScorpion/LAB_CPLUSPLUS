#if !defined(maze_h)
#define maze_h
#include <iostream>
#include <vector>
class Maze{
    public:
        explicit Maze(std::string file);
        Maze(std::string file, int dim);
        bool is_exit(int x, int y){return map_[x][y].exit_;}
        bool is_wall(int x, int y){return map_[x][y].wall_;}
        bool is_robot(int x, int y){return map_[x][y].robot_;}
        bool is_empty(int x, int y){return !(map_[x][y].exit_ and map_[x][y].robot_ and map_[x][y].wall_);}
        int size(){return dim_;}
        //void set_robot(const Robot r);
        friend std::ostream& operator<<(std::ostream& os, Maze val);
    private:
        struct Cell{
            bool wall_ = false;
            bool robot_ = false;
            bool exit_ = false;
            Cell(const char& val);
        };
        void fill_map();
        friend std::ostream& operator<<(std::ostream& os, Cell val);
        friend std::ostream& operator<<(std::ostream& os, std::vector<Cell> vec);
        std::vector<std::vector<Cell>> map_;
        int dim_;
        int rob_x_;
        int rob_y_;
};

#endif // maze_h
