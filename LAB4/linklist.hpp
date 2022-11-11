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
link<T>* list<T>::navigate(int index){  //con indici positivi parte da front, con indici negativi da back
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
    back = lnk::push_back(back, new link(obj));
    size++;
}
template<typename T>
void list<T>::push_front(T obj){
    front = lnk::push_front(front, new link(obj));
    size++;
}
template<typename T>
T list<T>::pop_back(){
    back = back->advance(-1);
    link<T>* elem = lnk::pop_back(back);
    T obj = elem->value;
    delete elem;
    size--;
    if(!back->prev)front=back;
    return obj;
}
template<typename T>
T list<T>::pop_front(){
    front = front->advance(1);
    link<T>* elem = lnk::pop_front(front);
    T obj = elem->value;
    delete elem;
    size--;
    if(!front->next)back=front;
    return obj;
}
template<typename T>
void list<T>::ins_before(T obj, int index){
    link<T>* elem  = navigate(index)->insert(new link<T>{obj});
    if(!elem->prev)front = elem;
    size++;
}
template<typename T>
void list<T>::ins_after(T obj, int index){
    link<T>* elem  = navigate(index)->insert(new link<T>{obj});
    if(!elem->next)back = elem;
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
