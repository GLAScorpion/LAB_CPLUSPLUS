#ifndef linklist_hpp
#define linklist_hpp
#include <iostream>
#include "link.h"
#include "linklist.h"
#include <vector>
template<typename T>
list<T>::list(std::initializer_list<T> lst){
    dim = lst.size();
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
:dim{lst.dim},front{lst.front->clone_lst()},back{front->back()}{}
template<typename T>
list<T>::list(list<T>&& lst)
:dim{lst.dim},front{lst.front},back{lst.back}
{//costruttore di spostamento
    lst.front = nullptr;
    lst.back = nullptr;
    lst.dim = 0;
}
template<typename T>
list<T>& list<T>::operator=(const list<T>& lst){ //assegnamento per copia
    link<T>* new_lst = lst.front->clone_lst();
    delete front;
    dim = lst.dim;
    front = new_lst;
    back = front->back();
    return *this;
}
template<typename T>
list<T>& list<T>::operator=(list<T>&& lst){   //assegnamento per spostamento
    delete front;
    front = lst.front;
    back = lst.back;
    dim = lst.dim;
    lst.front = nullptr;
    lst.back = nullptr;
    lst.dim = 0;
    return *this;
}
template<typename T>
link<T>* list<T>::navigate(int index){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    if(index<0) throw std::invalid_argument("Negative index not allowed");
    if(index == 0) return front;
    if(index == dim -1) return back;
    if(index>=dim) throw std::invalid_argument("List out of bounds");
    if(index <= dim/2){
        return front->advance(index);
    }
    return back->advance(-(dim-1-index));
}
template<typename T>
const T list<T>::remove(int index){
    link<T>* elem = navigate(index);
    if(elem == front) return pop_front();
    if(elem == back) return pop_back();
    dim--;
    return lnk::erase(elem);
}
template<typename T>
void list<T>::push_back(const T& obj){
    dim++;
    if(!back){
        back = front = new link<T>(obj);
        return;
    }
    back = back->add(new link<T>{obj});
}
template<typename T>
void list<T>::push_front(const T& obj){
    dim++;
    if(!front){
        back = front = new link<T>(obj);
        return;
    }
    front = front->insert(new link<T>{obj});
}
template<typename T>
const T list<T>::pop_back(){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = back;
    back = back->advance(-1);
    elem = elem->extract();
    T obj = elem->value;
    dim--;
    if(!back){
        back = nullptr;
        return obj;
    }
    if(!back->hasprev())front=back;
    delete elem;
    return obj;
}
template<typename T>
const T list<T>::pop_front(){
    if((front == back)and(front == nullptr)) throw std::invalid_argument("Empty list"); 
    link<T>* elem = front;
    front = front->advance(1);
    elem = elem->extract();
    T obj = elem->value;
    dim--;
    if(!front){
        back = nullptr;
        return obj;
    }
    if(!front->hasnext())back = front;
    delete elem;
    return obj;
}
template<typename T>
void list<T>::ins_before(const T& obj, int index){
    link<T>* elem  = navigate(index)->insert(new link<T>{obj});
    if(!elem->hasprev())front = elem;
    dim++;
}
template<typename T>
void list<T>::ins_after(const T& obj, int index){
    link<T>* elem  = navigate(index)->add(new link<T>{obj});
    if(!elem->hasnext())back = elem;
    dim++;
}
template<typename T>
const std::string list<T>::print() const{
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
int list<T>::find(const T& obj) const{
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
void list<T>::list_ins(list<T>& lst, int index){
    link<T>* indexed = nullptr;
    if(index!=-1)indexed = navigate(index);
    link<T>* front_clone_lst = lst.front->clone_lst();
    link<T>* back_clone_lst = front_clone_lst->back();
    if(index==-1){
        back_clone_lst->join(front);
        front = front_clone_lst;
        dim += lst.dim;
        return;
    }
    if(indexed == back){
        back->join(front_clone_lst);
        back = back_clone_lst;
        dim += lst.dim;
        return;
    }
    navigate(index+1)->join(back_clone_lst);
    indexed->join(front_clone_lst);
    dim += lst.dim;
}
template<typename T>
list<T> list<T>::extractlist(int first, int num){
    if((num<0)or(first<-1))throw std::invalid_argument("Negative index not allowed");
    if(num == 0) return list<T>{remove(first)}; 
    link<T>* num_elem = navigate(first + num);
    link<T>* first_elem_prev = nullptr;
    if(first > 0)first_elem_prev = navigate(first-1); 
    link<T>* num_elem_next = num_elem->unlink();
    link<T>* first_elem = front;
    if(first_elem_prev)first_elem = first_elem_prev->unlink();
    dim = dim - num - 1;
    if(first_elem_prev){
        if(num_elem_next){
            first_elem_prev->join(num_elem_next);
        }else{
            back = first_elem_prev;
        }
    }else{
        if(num_elem_next){
            front = num_elem_next;
        }else{
            front = nullptr;
            back = nullptr;
        }
    }
    list<T> lst;
    lst.dim = num+1;
    lst.front = first_elem;
    lst.back = num_elem;
    return lst;
}
//HELPER FUNCTION
template<typename T>
list<T> list<T>::sublist(int first, int num) const{
    list<T> tmp = *this;
    return tmp.extractlist(first,num);
}
template<typename T>
list<T> operator+(list<T> lst1,list<T> lst2){
    list<T> tmp = lst1;
    tmp.list_ins(lst2,tmp.size()-1);
    return tmp;
}
template<typename T>
list<T> to_list(std::vector<T> lst){
    list<T> tmp;
    for(int i=0;i<lst.size();i++){
        tmp.push_back(lst[i]);
    }
    return tmp;
}
template<typename T>
std::vector<T> to_vector(list<T> lst){
    std::vector<T> vec;
    for(int i=0; i<lst.size();i++){
        vec.push_back(lst[i]);
    }
    return vec;
}
#endif
