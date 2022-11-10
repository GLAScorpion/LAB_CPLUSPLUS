#include <iostream>
#include "link.h"
class list{
    public:
        ~list(){delete front;}
        list(): size{0},front{nullptr},back{nullptr}{};
        list(std::initializer_list<std::string> lst);
        void push_back(std::string s);
        void push_front(std::string s);
        std::string pop_back();
        std::string pop_front();
        void ins_before(std::string s, int index);
        void ins_after(std::string s, int index);
        std::string print();
        std::string& operator[](int s);
        int find(std::string s);
    private:
        int size;
        link* front;
        link* back;
};