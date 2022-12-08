#if !defined(maze_h)
#define maze_h
#include <iostream>
#include <vector>
class Maze{
    public:
        struct coord
        {
            coord(int x, int y):x_{x},y_{y}{}
            int x_;
            int y_;
            int serial_ = 0;
        };
        explicit Maze(const std::string& file);
        Maze(const std::string& file, int dim);
        bool move(int num, int x_offset, int y_offset);
        int find_robot(int serial) const;
        bool is_exit(int x, int y) const {return map_[y][x].exit_;}
        bool is_wall(int x, int y) const {return map_[y][x].wall_;}
        bool is_robot(int x, int y) const {return map_[y][x].robot_;}
        bool is_empty(int x, int y) const {return !(map_[y][x].exit_ or map_[y][x].robot_ or map_[y][x].wall_);}
        int size() const {return size_;}
        const coord& get_robot(int num) const {return robots_.at(num - 1);}
        int get_robot_count() const {return robots_.size();}
        void set_robot(int num, int serial){robots_.at(num - 1).serial_ = serial;}
        friend std::ostream& operator<<(std::ostream& os, const Maze& val);
    private:
        struct Cell{
            bool wall_ = false;
            bool robot_ = false;
            bool exit_ = false;
            Cell(const char& val);
        };
        void fill_map();
        friend std::ostream& operator<<(std::ostream& os, const Cell& val);
        friend std::ostream& operator<<(std::ostream& os, const std::vector<Cell>& vec);
        std::vector<std::vector<Cell>> map_;
        std::vector<coord> robots_;
        int size_;
};
#endif // maze_h
