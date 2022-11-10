#include <iostream>
#include "link.h"
using namespace std;
int main(){
    link* test = new link{"str1"};
    push_back(test,new link{"str2"});
    push_front(test, new link{"str3"});
    cout << print_all(test) << endl;
    pop_back(test);
    cout << print_all(test) << endl;
    test = test->front();
    pop_back(test);
    cout << print_all(test) << endl;
}