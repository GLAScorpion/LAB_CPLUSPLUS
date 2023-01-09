#if !defined(robot_h)
#define robot_h
#include <iostream>
#include "maze.h"
#include <random>
/*
     -1   0   1
-1    x   x   x
0     x   R   x
1     x   x   x

*/
class Robot{
    public:
        Robot()
        {
            static std::random_device rand_serial;
            static std::uniform_int_distribution<int> dist(0,INT32_MAX);
            serial_ = dist(rand_serial);
        } 
        //some robots contain extra data, so splicing is an issue
        Robot(const Robot&) = delete;
        Robot& operator=(const Robot&) = delete;
        //returns a pointer to a clone of this, uses the "new" operator, garbage collection needed in case of use
        virtual Robot* clone_pointer() const{return nullptr;}
        virtual bool move(Maze& maze) = 0;
        void set_serial(int serial){
            if(serial < 0 or serial > INT32_MAX) throw std::invalid_argument("Invalid serial format");
            serial_ = serial;
        }
        int serial() const {return serial_;}
    private:
        int serial_;
};
#endif