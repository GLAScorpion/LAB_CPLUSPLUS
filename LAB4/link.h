#ifndef link_h
#define link_h
#include <iostream>
#include <string.h>
template<typename T>
class link{
    public:
        T value;
        //COSTRUTTORI
        explicit link(const T& val, link* previous = nullptr, link* successive =nullptr)
        : value{val}, prev{previous}, next{successive} {}
        ~link(){ if(prev)prev->next = nullptr;delete next; }
        //MEMBER FUNCTIONS
        link* search(T val);
        // this_prev -- new_elem -- this
        link* insert(link* new_elem);
        // this -- new_elem -- this_nxt
        link* add(link* new_elem);
        link* back(); //trova l'ultimo elemento, next == nullptr
        link* front(); //trova il primo elemento, prev == nullptr
        link* advance(int n);
        link* extract();     //"erase" come visto a lezione, nessuna gestione della memoria
        //FUNZIONI NON RICHIESTE DALLA CONSEGNA
        link* clone_lst();   //ritorna un puntatore a un lista diversa, ma con gli stessi contenuti da this a back()
        bool hasnext(){return next;}
        bool hasprev(){return prev;}
        void join(link* lst);   //collega due link, in particolare lst deve aver uno dei due puntatori a nullptr
    private:
        link* prev;
        link* next;
};
//HELPER FUNCTIONS
namespace lnk{
    template <typename T>
    std::string print_all(link<T>* lst);
    template <typename T>
    T erase(link<T>* elem); //ho reinterpretato erase come un'eliminazione con distruzione, ritorna solo il valore del link
    template <typename T>
    link<T>* pop_back(link<T>* lst);
    template <typename T>
    link<T>* pop_front(link<T>* lst);
    template <typename T>
    link<T>* push_back(link<T>* lst, link<T>* elem);
    template <typename T>
    link<T>* push_front(link<T>* lst, link<T>* elem);
}
#include "link.hpp"
#endif
