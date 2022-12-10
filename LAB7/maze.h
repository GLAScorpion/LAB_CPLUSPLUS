#if !defined(maze_h)
#define maze_h
#include <iostream>
#include <vector>
class Maze{
    public:
        struct RobPos
        {
            RobPos(int x, int y):x_{x},y_{y}{}
            int x_;
            int y_;
            int serial_ = 0;
        };
        explicit Maze(const std::string& file);
        bool move(int num, int x_offset, int y_offset);
        int find_robot(int serial) const;
        const std::vector<bool> wall_pos(int x, int y) const;
        bool is_exit(int x, int y) const;
        bool is_wall(int x, int y) const;
        bool is_robot(int x, int y) const;
        bool is_empty(int x, int y) const;
        bool in_range(int x, int y) const {return x < size_ and y < size_ and y >= 0 and x >= 0;}
        int size() const {return size_;}
        const RobPos& get_robot(int num) const {return robots_.at(num - 1);}
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
        std::vector<RobPos> robots_;
        int size_;
};
#endif // maze_h
