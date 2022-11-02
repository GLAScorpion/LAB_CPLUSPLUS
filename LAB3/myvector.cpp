#include "myvector.h"
//member functions
/*
vector::vector(unsigned int dim)
    : size {dim} , elem {new double[dim]}
{
    }
*/
vector::vector(int dim)
: size {dim}
{
    if(dim <= 0){
            throw std::invalid_argument("Invalid vector size");
    }
   elem = new double[dim];
}
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