#ifndef myvector_hpp
#define myvector_hpp
#include "myvector.h"
#include <iostream>
//member functions
const int initial_size=10;
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
    if(num < elem_size) return;
    T* tmp = new T[num];
    std::copy(elem, elem + elem_num, tmp);
    delete[] elem;
    elem = tmp;
    elem_size = num;
}
//costruttori
template<typename T>
vector<T>::vector()
:elem_size{initial_size}, elem_num{0},elem{new T[elem_size]}
{}

template<typename T>
vector<T>::vector(int dim)
: elem_size{dim}, elem_num {dim}
{
    if(dim <= 0){
            throw std::invalid_argument("Invalid vector dim");
    }
    if(elem_size<initial_size) elem_size = initial_size;
    elem = new T[elem_size];
}
template<typename T>
vector<T>::vector(std::initializer_list<T> lst) //costruttore con initializer list
:elem_size{lst.size()},elem_num{lst.size()}
{   
    if(elem_size<initial_size) elem_size = initial_size;
    elem = new T[elem_size];
    std::copy(lst.begin(), lst.end(), elem);
}
//costruttore di copia
template<typename T>
vector<T>::vector(const vector<T>& vec)
    : elem_num{vec.elem_num},elem_size{vec.elem_size},elem{new T[elem_size]}
{
    std::copy(vec.elem, vec.elem + elem_num, elem);
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& vec){//assegnamento per copia
    T* tmp = new T[vec.elem_size];
    std::copy(vec.elem, vec.elem + vec.elem_num, tmp);
    delete[] elem;
    elem = tmp;
    elem_num = vec.elem_num;
    elem_size = vec.elem_size;
    return *this;
} 
//costruttore di spostamento
template <typename T>
vector<T>::vector(vector<T>&& vec)
    : elem_num{vec.elem_num}, elem_size{vec.elem_size},elem{vec.elem}
{   
    vec.elem_size = 0;
    vec.elem_num = 0;
    vec.elem = nullptr;
}
template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& vec){//assegnamento per spostamento
    T* tmp = new T[vec.elem_size];
    std::copy(vec.elem, vec.elem + vec.elem_num, tmp);
    delete[] elem;
    elem_size = vec.elem_size;
    elem_num = vec.elem_num;
    vec.elem = nullptr;
    vec.elem_num = 0;
    vec.elem_size = 0;
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