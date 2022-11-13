#include "myvector.h"
#include <iostream>
std::ostream& operator<<(std::ostream& os, vector& vec){
    os << "{ ";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i] << " ";
    }
    os << "}";
    return os;
}
//member functions
/*
vector::vector(unsigned int dim)
    : dim {dim} , elem {new double[dim]}
{
    }
*/

int vector::size() const{
    return dim;
}
vector::~vector(){
    delete[] elem;
}
double& vector::operator[](int index){
    if(index >= dim or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    return elem[index];
}
double vector::operator[](int index) const{
    if(index >= dim  or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    return elem[index];
}
double vector::safe_get(int index) const{
    if(index >= dim  or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    return elem[index];
}
void vector::safe_set(int index, double value){
    if(index >= dim or index < 0){
            throw std::invalid_argument("Index out of bounds");
    }
    elem[index]  = value;
}
//costruttori
vector::vector(int dim)
: dim {dim}
{
    if(dim <= 0){
            throw std::invalid_argument("Invalid vector dim");
    }
   elem = new double[dim];
}
vector::vector(std::initializer_list<double> lst) //costruttore con initializer list
    : dim{lst.size()}, elem{new double[dim]}
{
    std::copy(lst.begin(), lst.end(), elem);
}
vector::vector(const vector& vec)
    : dim{vec.dim}, elem{new double[dim]}
{//costruttore di copia
    std::copy(vec.elem, &vec.elem[dim], elem);
}
vector& vector::operator=(const vector& vec){//assegnamento per copia
    if(dim < vec.dim){                     //variabile dim è costante, non posso cambiare la dimensione al vettore
        throw std::invalid_argument("Vector is too small");
    }
    std::copy(vec.elem, vec.elem + vec.dim, elem);
    if(dim > vec.dim){                    //a causa della dim costante riempio a zero gli spazi non sovrascritti da std::copy
        for(int i = vec.dim; i < dim; i++){
            elem[i] = {0.0};
        }
    }
    return *this;
} 

vector::vector(vector&& vec)
    : dim{vec.dim}, elem{vec.elem}
{//costruttore di spostamento
    vec.elem = nullptr;
}

vector& vector::operator=(vector&& vec){//assegnamento per spostamento
    if(dim < vec.dim){                     //variabile dim è costante, non posso cambiare la dimensione al vettore
        throw std::invalid_argument("Vector is too small");
    }
    std::copy(vec.elem, vec.elem + vec.dim, elem);
    if(dim > vec.dim){                    //a causa della dim costante riempio a zero gli spazi non sovrascritti da std::copy
        for(int i = vec.dim; i < dim; i++){
            elem[i] = {0.0};
        }
    }
    delete[] vec.elem;
    vec.elem = nullptr;
    return *this;
} 
