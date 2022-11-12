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
        T print() const;
        T operator[](int n) const;
        T& operator[](int n);
        int find(T obj) const;
        T remove(int index);
        int get_size() const{return size;}
        void list_ins(list<T>& lst, int index);
        list(const list& lst);//costruttore di copia
        list(list&& lst);//costruttore di spostamento
        list<T>& operator=(const list<T>& lst); //assegnamento per copia
        list<T>& operator=(list<T>&& lst); //assegnamento per spostamento
    private:
        link<T>* navigate(int index);
        int size;
        link<T>* front;
        link<T>* back;
};
template<typename T>
list<T> operator+(list<T> lst1,list<T> lst2);
template<typename T>
list<T> operator-(list<T> lst1,list<T> lst2);
template<typename T>
list<T> to_list(std::vector<T> lst1);
#include "linklist.hpp"
#endif