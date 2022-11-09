#include <iostream>
#include <string.h>
class link{
    public:
        //COSTRUTTORI
        link(const std::string& val, link* previous = nullptr, link* successive =nullptr)
        : value{val}, prev{previous}, next{successive} {}
        ~link(){ delete prev; delete next; }
        //MEMBER FUNCTIONS
        link* insert(link* new_elem);
        link* add(link* new_elem);
        link* back(); //trova il primo elemento, next == nullptr
        link* front(); //trova l'ultimo elemento, prev == nullptr
        link* find(std::string val);
        link* advance(int n);
        link* extract();     //"erase" come visto a lezione, nessuna gestione della memoria
        link* find(std::string val);
        std::string get_value(){ return value; }
    private:
        std::string value;
        link* prev;
        link* next;
};
//HELPER FUNCTIONS
std::string erase(link* elem); //ho reinterpretato erase come un'eliminazione con distruzione, ritorna solo il valore del link
link* pop_back(link* lst);
link* pop_front(link* lst);
link* push_back(link* lst, link* elem);
link* push_front(link* lst, link* elem);
