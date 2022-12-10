#if !defined(dummy_bot_h)
#define dummy_bot_h
#include <iostream>
#include "robot.h"
class DummyBot : public Robot{
    public:
        DummyBot():Robot(){}
        bool move(Maze& maze) override{return false;}
};
#endif // dummy_bot_h
