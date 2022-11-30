#ifndef myvector_hpp
#define myvector_hpp
#include "myvector.h"
#include <iostream>
//member functions
const initial_size=10;
template <typename T>
T& vector<T>::at(int index){
    if(index <0 or index >= elem_num) throw std::invalid_argument("Array out of bounds");
    return elem[index];
}
template <typename T>
const T& vector<T>::at(int index) const{
    if(index <0 or index >= elem_num) throw std::invalid_argument("Array out of bounds");
    return elem[index];
}
template <typename T>
void vector<T>::reserve(int num){
    if(num < capacity) return;
    T* tmp = new T[num];
    std::copy(elem, elem + elem_num, tmp);
    delete[] elem;
    elem = tmp;
    capacity = num;
}
//costruttori
template<typename T>
vector<T>::vector()
:capacity{initial_size}, elem_num{0},elem{new T[capacity]}
{}

template<typename T>
vector<T>::vector(int dim) explicit
: capacity{dim}, elem_num {dim}
{
    if(dim <= 0){
            throw std::invalid_argument("Invalid vector dim");
    }
    if(capacity<initial_size) capacity = initial_size;
    elem = new T[capacity];
}
template<typename T>
vector<T>::vector(std::initializer_list<T> lst) //costruttore con initializer list
:capacity{lst.size()},elem_num{lst.size()}
{   
    if(capacity<initial_size) capacity = initial_size;
    elem = new T[capacity];
    std::copy(lst.begin(), lst.end(), elem);
}
//costruttore di copia
template<typename T>
vector<T>::vector(const vector<T>& vec)
    : elem_num{vec.elem_num},capacity{vec.capacity} elem{new T[capacity]}
{
    std::copy(vec.elem, vec.elem + elem_num, elem);
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& vec){//assegnamento per copia
    T* tmp = new T[vec.capacity];
    std::copy(vec.elem, vec.elem + vec.elem_num, tmp);
    delete[] elem;
    elem = tmp;
    elem_num = vec.elem_num;
    capacity = vec.capacity;
    return *this;
} 
//costruttore di spostamento
template <typename T>
vector<T>::vector(vector<T>&& vec)
    : elem_num{vec.elem_num}, capacity{vec.capacity},elem{vec.elem}
{   
    vec.capacity = 0;
    vec.elem_num = 0;
    vec.elem = nullptr;
}
template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& vec){//assegnamento per spostamento
    T* tmp = new T[vec.capacity];
    std::copy(vec.elem, vec.elem + vec.elem_num, tmp);
    delete[] elem;
    capacity = vec.capacity;
    elem_num = vec.elem_num;
    vec.elem = nullptr;
    vec.elem_num = 0;
    vec.capacity = 0;
    return *this;
} 
//helper functions
template <typename T>
std::ostream& operator<<(std::ostream& os, vector<T>& vec){
    os << "{ ";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i] << " ";
    }
    os << "}";
    return os;
}
#endif