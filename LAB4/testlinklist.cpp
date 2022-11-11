#include <iostream>
#include "linklist.h"
using namespace std;
int main(){
    list<string> l = {"str1", "str2", "str3"};
    cout << l.print()<<endl;
    l.push_back("str4");
    l.push_front("str5");
    cout<<l.print()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<l.print()<<endl;
    l[1] = "pino";
    cout<<l.print()<<endl;
    l.remove(1);
    cout<<l.print()<<endl;
    l.remove(1);
    cout<<l.print()<<endl;
    l.remove(0);
    cout<<l.print()<<endl;
    l.push_back("str4");
    l.push_front("str5");
    cout<<l.print()<<endl;
}