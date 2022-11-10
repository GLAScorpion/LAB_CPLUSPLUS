#include <iostream>
#include "link.h"
#include "linklist.h"
list::list(std::initializer_list<std::string> lst){
    size = lst.size();
    const std::string* s = lst.begin();
    link* elem = new link(s[0]);
    front = elem;
    for(int i = 1; &s[i] <= lst.end(); i++){
        elem = elem->add(new link(s[i]));
    }
    back = elem;
}
void list::push_back(std::string s){
    back = lnk::push_back(back, new link(s));
    size++;
}
void list::push_front(std::string s){
    front = lnk::push_front(front, new link(s));
    size++;
}
std::string list::pop_back(){
    back = back->advance(-1);
    link* elem = lnk::pop_back(back);
    std::string s = elem->get_value();
    delete elem;
    size--;
    return s;
}
std::string list::pop_front(){
    front = front->advance(1);
    link* elem = lnk::pop_back(front);
    std::string s = elem->get_value();
    delete elem;
    size--;
    return s;
}
void list::ins_before(std::string s, int index){
    
    front->advance(index);
    size++;
}
void list::ins_after(std::string s, int index){
    size++;
}
std::string list::print(){
    return lnk::print_all(front);
}
std::string& list::operator[](int n){
    link* elem = front->advance(n);
    if(!elem) throw std::invalid_argument("List out of bound");
    return elem->get_value_ref();
}
int list::find(std::string s){
    link* elem = front;
    int counter = 0;
    while(elem){
        if(elem->get_value() == s){
            return counter;
        }
        elem = elem->advance(1);
    }
    return -1;
}