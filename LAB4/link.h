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
        link* search(const T& val);
        // this_prev -- new_elem -- this
        link* insert(link* new_elem);
        // this -- new_elem -- this_nxt
        link* add(link* new_elem);
        //trova l'ultimo elemento, next == nullptr
        link* back(); 
        //trova il primo elemento, prev == nullptr
        link* front(); 
        link* advance(int n);
        link* extract();     //"erase" come visto a lezione, nessuna gestione della memoria
        //FUNZIONI NON RICHIESTE DALLA CONSEGNA
        //ritorna un puntatore a un lista diversa, ma con gli stessi contenuti da this a back()
        link* clone_lst();   
        bool hasnext(){return next;}
        bool hasprev(){return prev;}
        //collega due link, in particolare lst deve aver uno dei due puntatori a nullptr
        void join(link* lst);   
        //scollega this da next, e ritorna next
        link* unlink();
    private:
        link* prev;
        link* next;
};
//HELPER FUNCTIONS
namespace lnk{
    template <typename T>
    const std::string print_all(link<T>* lst);
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
