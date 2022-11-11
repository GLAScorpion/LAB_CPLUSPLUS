#ifndef linklist_hpp
#define linklist_hpp
#include <iostream>
#include "link.h"
#include "linklist.h"
using std::cout;
template<typename T>
list<T>::list(std::initializer_list<T> lst){
    size = lst.size();
    const T* obj = lst.begin();
    link<T>* elem = new link<T>(obj[0]);
    front = elem;
    for(int i = 1; &obj[i] != lst.end(); i++){
        elem = elem->add(new link<T>(obj[i]));
    }
    back = elem;
}
template<typename T>
link<T>* list<T>::navigate(int index){ //con indici positivi parte da front, con indici negativi da back
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    if((index == 0)or(index==-size)) return front;
    if((index == size -1)or(index==-1)) return back;
    if(abs(index)>=size) throw std::invalid_argument("List out of bounds");
    if(index>0) return front->advance(index);
    return back->advance(index+1);
}
template<typename T>
T list<T>::remove(int index){
    link<T>* elem = navigate(index);
    if(elem == front) return pop_front();
    if(elem == back) return pop_back();
    return lnk::erase(elem);
}
template<typename T>
void list<T>::push_back(T obj){
    size++;
    if(!back){
        back = front = new link<T>(obj);
        return;
    }
    this->ins_after(T,-1);
   // back = lnk::push_back(back, new link<T>(obj));
}
template<typename T>
void list<T>::push_front(T obj){
    size++;
    if(!front){
        back = front = new link<T>(obj);
        return;
    }
    this->ins_before(T,0);
    //front = lnk::push_front(front, new link<T>(obj));
    
}
template<typename T>
T list<T>::pop_back(){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = back;
    back = back->advance(-1);
    elem = elem->extract();
    T obj = elem->value;
    size--;
    if(!back) return obj;
    if(!back->hasprev())front=back;
    delete elem;
    return obj;
}
template<typename T>
T list<T>::pop_front(){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = front;
    front = front->advance(1);
    elem = elem->extract();
    T obj = elem->value;
    size--;
    if(!front)return obj;
    if(!front->hasnext())back = front;
    delete elem;
    return obj;
}
template<typename T>
void list<T>::ins_before(T obj, int index){
    link<T>* elem  = navigate(index)->insert(new link<T>{obj});
    size++;
}
template<typename T>
void list<T>::ins_after(T obj, int index){
    link<T>* elem  = navigate(index)->add(new link<T>{obj});
    size++;
}
template<typename T>
T list<T>::print(){
    return lnk::print_all(front);
}
template<typename T>
T& list<T>::operator[](int n){
    return navigate(n)->value;
}
template<typename T>
int list<T>::find(T obj){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = front;
    int counter = 0;
    while(elem){
        if(elem->value == obj){
            return counter;
        }
        elem = elem->advance(1);
    }
    return -1;
}
#endif
