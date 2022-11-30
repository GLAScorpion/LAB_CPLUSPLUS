#ifndef myvector_h
#define myvector_h
#include <iostream>
template <typename T>
class vector{
    public:
    //member functions
        int size() const{return elem_num;}
        int capacity() const{return capacity;}
        T& operator[](int index){return elem[index];}
        const T& operator[](int index) const{return elem[index];}
        T& at(int index);
        const T& at(int index) const;
        void reserve(int num);
    //costruttori
        //costruttore di default
        vector();
        explicit vector(int dim);
        //costruttore di copia
        vector(const vector& vec);
        //costruttore di spostamento
        vector(vector&& vec);
        vector& operator=(const vector& vec); //assegnamento per copia
        vector& operator=(vector&& vec); //assegnamento per spostamento
        ~vector(){delete[] elem;}
        vector(std::initializer_list<T> lst);
    private:
        int capacity;
        int elem_num; //numero di elementi 
        T* elem = nullptr;    
};
template<typename T>
std::ostream& operator<<(std::ostream& os, vector<T>& vec);
#include "myvector.hpp"
#endif
