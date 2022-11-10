#include <iostream>
#include "link.h"
using namespace std;
using namespace lnk;
int main(){
    link<string>* test = new link<string>{"str1"};
    push_back(test,new link<string>{"str2"});
    push_front(test, new link<string>{"str3"});
    cout << print_all(test) << endl;
    pop_back(test);
    cout << print_all(test) << endl;
    test = test->front();
    pop_back(test);
    cout << print_all(test) << endl;
    push_back(test,new link<string>{"str2"});
    push_front(test, new link<string>{"str3"});
    link<string>* tmp = test->front();
    cout<<print_all(tmp)<<endl;
    test = test->advance(1);
    erase(test);
    cout << print_all(tmp) << endl;
}