#include <iostream>
#include "link.h"
//HELPER FUNCTIONS
link* pop_back(link* lst){
    return lst->back()->extract();
}
link* pop_front(link* lst){
    return lst->front()->extract();
}
link* push_back(link* lst, link* elem){
    return lst->back()->add(elem);
}
link* push_front(link* lst, link* elem){
    return lst->front()->insert(elem);
}
std::string erase(link* elem){
    elem->extract();
    std::string tmp_val = elem->get_value();
    delete elem;
    return tmp_val;
}
std::string print_all(link* lst){
    std::string s = "{ ";
    link* elem = lst->front();
    while(elem){
        s += "[" + elem->get_value() + "] ";
        elem = elem->advance(1);
    }
    s+= "}";
    return s;
}
//MEMBER FUNCTIONS
link* link::search(std::string val){
    link* elem = this;
    link* old_elem = elem->next;
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
link* link::insert(link* new_elem) { // this_prev -- new_elem -- this
    if (!new_elem) return this;
    if (!this) return new_elem;
    new_elem->next = this;
    if (this->prev) this->prev->next = new_elem;
    new_elem->prev = this->prev;
    this->prev = new_elem;
    return new_elem;
}
link* link::add(link* new_elem) { // this -- new_elem -- this_nxt
    if (!new_elem) return this;
    if (!this) return new_elem;
    new_elem->prev = this;
    if (this->next) this->next->prev = new_elem;
    new_elem->next = this->next;
    this->next = new_elem;
    return new_elem;
}
link* link::back(){ //trova il primo elemento, next == nullptr
    link* elem = this; 
    while(elem->next){
        elem = elem->next;
    }
    return elem;
} 
link* link::front(){    //trova l'ultimo elemento, prev == nullptr
    link* elem = this;
    while(elem->prev){
        elem = elem->prev;
    }
    return elem;
}
link* link::extract(){
    if(this->prev) this->prev->next = this->next;
    if(this->next) this->next->prev = this->prev;
    this->prev = nullptr;
    this->next = nullptr;
    return this;
}

link* link::advance(int n){
    link* elem = this;
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