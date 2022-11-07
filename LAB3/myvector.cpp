#include "myvector.h"
#include <iostream>
std::ostream& operator<<(std::ostream& os, vector& vec){
    os << "{ ";
    for(int i = 0; i < vec.get_size(); i++){
        os << vec[i] << " ";
    }
    os << "}";
    return os;
}
//member functions
/*
vector::vector(unsigned int dim)
    : size {dim} , elem {new double[dim]}
{
    }
*/

int vector::get_size() const{
    return size;
}
vector::~vector(){
    delete[] elem;
}
double& vector::operator[](int index){
    if(index >= size or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    return elem[index];
}
double vector::operator[](int index) const{
    if(index >= size  or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    return elem[index];
}
double vector::safe_get(int index) const{
    if(index >= size  or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    return elem[index];
}
void vector::safe_set(int index, double value){
    if(index >= size or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    elem[index]  = value;
}
//costruttori
vector::vector(int dim)
: size {dim}
{
    if(dim <= 0){
            throw std::invalid_argument("Invalid vector size");
    }
   elem = new double[dim];
}
vector::vector(std::initializer_list<double> lst) //costruttore con initializer list
    : size{lst.size()}, elem{new double[size]}
{
    std::copy(lst.begin(), lst.end(), elem);
}
vector::vector(const vector& vec)
    : size{vec.size}, elem{new double[size]}
{//costruttore di copia
    std::copy(vec.elem, &vec.elem[size], elem);
}
vector& vector::operator=(const vector& vec){//assegnamento per copia
    if(size < vec.size){                     //variabile size è costante, non posso cambiare la dimensione al vettore
        throw std::invalid_argument("Vector is too small");
    }
    std::copy(vec.elem, vec.elem + vec.size, elem);
    if(size > vec.size){                    //a causa della dim costante riempio a zero gli spazi non sovrascritti da std::copy
        for(int i = vec.size; i < size; i++){
            elem[i] = {0.0};
        }
    }
    return *this;
} 

vector::vector(vector&& vec)
    : size{vec.size}, elem{vec.elem}
{//costruttore di spostamento
    vec.elem = nullptr;
}

vector& vector::operator=(vector&& vec){//assegnamento per spostamento
    if(size < vec.size){                     //variabile size è costante, non posso cambiare la dimensione al vettore
        throw std::invalid_argument("Vector is too small");
    }
    std::copy(vec.elem, vec.elem + vec.size, elem);
    if(size > vec.size){                    //a causa della dim costante riempio a zero gli spazi non sovrascritti da std::copy
        for(int i = vec.size; i < size; i++){
            elem[i] = {0.0};
        }
    }
    delete[] vec.elem;
    vec.elem = nullptr;
    return *this;
} 
