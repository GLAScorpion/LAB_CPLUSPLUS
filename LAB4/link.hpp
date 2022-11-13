#ifndef link_hpp
#define link_hpp
#include <iostream>
#include "link.h"
//HELPER FUNCTIONS
template <typename T>
link<T>* lnk::pop_back(link<T>* lst){
    return lst->back()->extract();
}
template <typename T>
link<T>* lnk::pop_front(link<T>* lst){
    return lst->front()->extract();
}
template <typename T>
link<T>* lnk::push_back(link<T>* lst, link<T>* elem){
    return lst->back()->add(elem);
}
template <typename T>
link<T>* lnk::push_front(link<T>* lst, link<T>* elem){
    return lst->front()->insert(elem);
}
template <typename T>
T lnk::erase(link<T>* elem){
    elem->extract();
    T tmp_val = elem->value;
    delete elem;
    return tmp_val;
}
template <typename T>
std::string lnk::print_all(link<T>* lst){
    std::string ss;
    if(!lst) return "{ }";
    std::string s = "{ ";
    link<T>* elem = lst;
    while(elem){
        s += "[" + elem->value + "] ";
        elem = elem->advance(1);
    }
    s+= "}";
    return s;
}
template<typename T>
link<T>* link<T>::clone_lst(){
    link<T>* elem = this;
    link<T>* out = new link<T>(value);
    elem=elem->advance(1);
    link<T>* front = out;
    while(elem){
        out->next = new link<T>(elem->value,out,nullptr);
        out = out->next;
        elem=elem->advance(1);
    }
    return front;
}
//MEMBER FUNCTIONS
template<typename T>
void link<T>::join(link<T>* lst){
    /*
    if(!((lst->prev) xor (lst->next))){
        throw std::invalid_argument("Invalid link. Front or back needed");
    }
    */
    if(lst->next){
        next = lst;
        lst->prev = this;
        return;
    }
    if(lst->prev){
        prev = lst;
        lst->next = this;
        return;
    }
}
template<typename T>
link<T>* link<T>::unlink(){
    if(!next) return nullptr;
    link<T>* nxt = next;
    next = nullptr;
    nxt->prev = nullptr;
    return nxt;
}
template <typename T>
link<T>* link<T>::search(T val){
    link<T>* elem = this;
    link<T>* old_elem = elem->next;
    do{
        if(elem->value == val) return elem;
        elem->prev;
    }while(elem);
    while(old_elem){
        if(old_elem->value == val) return elem;
        old_elem->next;
    }
    return nullptr;
}
template <typename T>
link<T>* link<T>::insert(link<T>* new_elem) { 
    if (!new_elem) return this;
    new_elem->next = this;
    if (this->prev) this->prev->next = new_elem;
    new_elem->prev = this->prev;
    this->prev = new_elem;
    return new_elem;
}
template <typename T>
link<T>* link<T>::add(link<T>* new_elem) { 
    if (!new_elem) return this;
    new_elem->prev = this;
    if (this->next) this->next->prev = new_elem;
    new_elem->next = this->next;
    this->next = new_elem;
    return new_elem;
}
template <typename T>
link<T>* link<T>::back(){ //trova l'ultimo elemento, next == nullptr
    link<T>* elem = this; 
    while(elem->next){
        elem = elem->next;
    }
    return elem;
} 
template <typename T>
link<T>* link<T>::front(){    //trova il primo elemento, prev == nullptr
    link<T>* elem = this;
    while(elem->prev){
        elem = elem->prev;
    }
    return elem;
}
template <typename T>
link<T>* link<T>::extract(){
    if(this->prev) this->prev->next = this->next;
    if(this->next) this->next->prev = this->prev;
    this->prev = nullptr;
    this->next = nullptr;
    return this;
}
template <typename T>
link<T>* link<T>::advance(int n){
    link<T>* elem = this;
    if(!elem) return nullptr;
    while(n > 0){
        if(!elem->next)return nullptr;
        elem = elem->next;
        n--;
    }
    while(n < 0){
        if(!elem->prev) return nullptr;
        elem = elem->prev;
        n++;
    }
    return elem;
}
#endif