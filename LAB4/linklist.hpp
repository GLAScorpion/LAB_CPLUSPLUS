#ifndef linklist_hpp
#define linklist_hpp
#include <iostream>
#include "link.h"
#include "linklist.h"
#include <vector>
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
list<T>::list(const list<T>& lst)//costruttore di copia
:size{lst.size},front{lst.front->clone_lst()},back{front->back()}{}
template<typename T>
list<T>::list(list<T>&& lst)
:size{lst.size},front{lst.front},back{lst.back}
{//costruttore di spostamento
    lst.front = nullptr;
    lst.back = nullptr;
    lst.size = 0;
}
template<typename T>
list<T>& list<T>::operator=(const list<T>& lst){ //assegnamento per copia
    link<T>* new_lst = lst.front->clone_lst();
    delete front;
    size = lst.size;
    front = new_lst;
    back = front->back();
    return *this;
}
template<typename T>
list<T>& list<T>::operator=(list<T>&& lst){   //assegnamento per spostamento
    delete front;
    front = lst.front;
    back = lst.back;
    size = lst.size;
    lst.front = nullptr;
    lst.back = nullptr;
    lst.size = 0;
    return *this;
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
    size--;
    return lnk::erase(elem);
}
template<typename T>
void list<T>::push_back(T obj){
    size++;
    if(!back){
        back = front = new link<T>(obj);
        return;
    }
    back = back->add(new link<T>{obj});
}
template<typename T>
void list<T>::push_front(T obj){
    size++;
    if(!front){
        back = front = new link<T>(obj);
        return;
    }
    front = front->insert(new link<T>{obj});
}
template<typename T>
T list<T>::pop_back(){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = back;
    back = back->advance(-1);
    elem = elem->extract();
    T obj = elem->value;
    size--;
    if(!back){
        back = nullptr;
        return obj;
    }
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
    if(!front){
        back = nullptr;
        return obj;
    }
    if(!front->hasnext())back = front;
    delete elem;
    return obj;
}
template<typename T>
void list<T>::ins_before(T obj, int index){
    link<T>* elem  = navigate(index)->insert(new link<T>{obj});
    if(!elem->hasprev())front = elem;
    size++;
}
template<typename T>
void list<T>::ins_after(T obj, int index){
    link<T>* elem  = navigate(index)->add(new link<T>{obj});
    if(!elem->hasnext())back = elem;
    size++;
}
template<typename T>
T list<T>::print() const{
    return lnk::print_all(front);
}
template<typename T>
T list<T>::operator[](int n) const{
    return navigate(n)->value;
}
template<typename T>
T& list<T>::operator[](int n){
    return navigate(n)->value;
}
template<typename T>
int list<T>::find(T obj) const{
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = front;
    int counter = 0;
    while(elem){
        if(elem->value == obj){
            return counter;
        }
        elem = elem->advance(1);
        counter++;
    }
    return -1;
}
template<typename T>
void list<T>::list_ins(list<T>& lst, int index){//inserisce una lista dopo l'index, ad indice -1 la inserisce in testa
    link<T>* indexed = nullptr;
    if(index!=-1)indexed = navigate(index);
    size += lst.get_size();
    link<T>* front_clone_lst = lst.front->clone_lst();
    link<T>* back_clone_lst = front_clone_lst->back();
    if(index==-1){
        front->join(back_clone_lst);
        front = front_clone_lst;
        return;
    }
    if(indexed == back){
        back->join(front_clone_lst);
        back = back_clone_lst;
        return;
    }
    navigate(index+1)->join(back_clone_lst);
    indexed->join(front_clone_lst);
}
//HELPER FUNCTION
template<typename T>
list<T> operator+(list<T> lst1,list<T> lst2){
    list<T> tmp = lst1;
    tmp.list_ins(lst2,tmp.get_size()-1);
    return tmp;
}
template<typename T>
list<T> to_list(std::vector<T> lst1){
    list<T> tmp;
    for(int i=0;i<lst1.size();i++){
        tmp.push_back(lst1[i]);
    }
    return tmp;
}
#endif
