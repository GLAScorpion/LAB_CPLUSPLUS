#ifndef link_h
#define link_h
#include <iostream>
#include <string.h>
class link{
    public:
        //COSTRUTTORI
        explicit link(const std::string& val, link* previous = nullptr, link* successive =nullptr)
        : value{val}, prev{previous}, next{successive} {}
        ~link(){ prev->next = nullptr;delete next; }
        //MEMBER FUNCTIONS
        link* insert(link* new_elem);
        link* add(link* new_elem);
        link* back(); //trova l'ultimo elemento, next == nullptr
        link* front(); //trova il primo elemento, prev == nullptr
        link* search(std::string val);
        link* advance(int n);
        link* extract();     //"erase" come visto a lezione, nessuna gestione della memoria
        link* find(std::string val);
        std::string get_value(){ return value; }
        std::string& get_value_ref();
    private:
        std::string value;
        link* prev;
        link* next;
};
//HELPER FUNCTIONS
namespace lnk{
    std::string print_all(link* lst);
    std::string erase(link* elem); //ho reinterpretato erase come un'eliminazione con distruzione, ritorna solo il valore del link
    link* pop_back(link* lst);
    link* pop_front(link* lst);
    link* push_back(link* lst, link* elem);
    link* push_front(link* lst, link* elem);
}
#include "link.hpp"
#endif