#include <iostream>
#include "link.h"
using namespace std;
int main(){
    link* test = new link{"str1"};
    cout << test <<endl;
    push_back(test,new link{"str3"});
    cout << test <<endl;
    push_front(test, new link{"str2"});
    cout << test <<endl;
    cout << print_all(test) << endl;
}