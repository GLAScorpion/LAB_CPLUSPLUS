#ifndef myvector_h
#define myvector_h
#include <iostream>
template <typename T>
class vector{
    public:
    //member functions
        int size() const{return elem_num;}
        int capacity() const{return elem_size;}
        T& operator[](int index){return elem[index];}
        const T& operator[](int index) const{return elem[index];}
        T& at(int index);
        const T& at(int index) const;
        void reserve(int num);
        void push_back(T val);
        T pop_back();
    //costruttori
        //costruttore di default
        vector();
        explicit vector(long unsigned int dim);
        //costruttore di copia
        vector(const vector& vec);
        //costruttore di spostamento
        vector(vector&& vec);
        //assegnamento per copia
        vector& operator=(const vector& vec); 
        //assegnamento per spostamento
        vector& operator=(vector&& vec); 
        ~vector(){delete[] elem;}
        vector(std::initializer_list<T> lst);
    private:
        long unsigned int elem_size; //memoria allocata
        long unsigned int elem_num; //numero di elementi 
        T* elem = nullptr;    
};
template<typename T>
std::ostream& operator<<(std::ostream& os,const vector<T>& vec);
#include "myvector.hpp"
#endif
