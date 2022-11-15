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
        list(): dim{0},front{nullptr},back{nullptr}{};
        list(std::initializer_list<T> lst);
        //MEMBER FUNCTIONS
        bool empty() {return dim==0;}
        void push_back(const T& obj);
        void push_front(const T& obj);
        const T pop_back();
        const T pop_front();
        void ins_before(const T& obj, int index);
        void ins_after(const T& obj, int index);
        const std::string print() const;
        T operator[](int n) const;
        T& operator[](int n);
        int find(const T& obj) const;
        const T remove(int index);
        int size() const{return dim;}
        //inserisce una lista dopo l'index, ad indice -1 la inserisce in testa
        void list_ins(list<T>& lst, int index);
        list(const list& lst);//costruttore di copia
        list(list&& lst);//costruttore di spostamento
        list<T>& operator=(const list<T>& lst); //assegnamento per copia
        list<T>& operator=(list<T>&& lst); //assegnamento per spostamento
        // taglia this a partire da this[first] per num elementi e ritorna il pezzo tagliato
        list<T> extractlist(int first, int num);
        list<T> sublist(int first, int num) const;
    private:
        link<T>* navigate(int index);
        int dim;
        link<T>* front;
        link<T>* back;
};
// ritorna una copia del segmento che inizia con this[first] e prosegue per num elementi
template<typename T>
list<T> operator+(list<T> lst1,list<T> lst2);
template<typename T>
list<T> to_list(std::vector<T> lst);
template<typename T>
std::vector<T> to_vector(list<T> lst);
#include "linklist.hpp"
#endif