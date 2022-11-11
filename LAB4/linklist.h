#ifndef linklist_h
#define linklist_h
#include <iostream>
#include "link.h"
#include <vector>
template <typename T>
class list{
    public:
        //COSTRUTTORI
        ~list(){delete front;}
        list(): size{0},front{nullptr},back{nullptr}{};
        list(std::initializer_list<T> lst);
        //MEMBER FUNCTIONS
        void push_back(T obj);
        void push_front(T obj);
        T pop_back();
        T pop_front();
        void ins_before(T obj, int index);
        void ins_after(T obj, int index);
        T print();
        T& operator[](int obj);
        int find(T obj);
        T remove(int index);
        int get_size(){return size;}
        void list_ins(list<T>& lst, int index);
    private:
        link<T>* navigate(int index);
        int size;
        link<T>* front;
        link<T>* back;
};
template<typename T>
list<T>& operator+(list<T> lst1,list<T> lst2);
template<typename T>
list<T>& operator-(list<T> lst1,list<T> lst2);
template<typename T>
list<T>& operator+(list<T> lst1,std::vector<T> lst2);
template<typename T>
list<T>& operator-(list<T> lst1,std::vector<T> lst2);
#include "linklist.hpp"
#endif