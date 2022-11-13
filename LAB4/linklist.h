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
        //inserisce una lista dopo l'index, ad indice -1 la inserisce in testa
        void list_ins(list<T>& lst, int index);
        list(const list& lst);//costruttore di copia
        list(list&& lst);//costruttore di spostamento
        list<T>& operator=(const list<T>& lst); //assegnamento per copia
        list<T>& operator=(list<T>&& lst); //assegnamento per spostamento
        // taglia this a partire da this[first] per num elementi e ritorna il pezzo tagliato
        list<T> extractlist(int first, int num);
    private:
        link<T>* navigate(int index);
        int size;
        link<T>* front;
        link<T>* back;
};
// ritorna una copia del segmento che inizia con this[first] e prosegue per num elementi
template<typename T>
list<T> sublist(list<T> source,int first, int num);
template<typename T>
list<T> operator+(list<T> lst1,list<T> lst2);
template<typename T>
list<T> operator-(list<T> lst1,list<T> lst2);
template<typename T>
list<T> to_list(std::vector<T> lst1);
#include "linklist.hpp"
#endif