#include <iostream>
#include "linklist.h"
#include <vector>
using namespace std;
int main(){
    list<string> l = {"str1", "str2", "str3"};
    cout << l.print()<<" "<<l.get_size()<<endl;
    l.push_back("str4");
    l.push_front("str5");
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l[1] = "pino";
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.remove(1);
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.remove(1);
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.remove(0);
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.push_front("str4");
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.push_back("str5");
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.ins_before("hello",1);
    l.ins_after("ciao",2);
    cout<<l.print()<<" "<<l.get_size()<<endl;
    list<string> l2 = {"c++", "java","python"};
    l.list_ins(l2,-1);
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<l.print()<<" "<<l.get_size()<<endl;
    cout<<l.find("str4")<<endl;
    cout<<l.find("gio")<<endl;
}
