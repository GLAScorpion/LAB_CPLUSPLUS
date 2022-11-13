#include <iostream>
#include "linklist.h"
#include <vector>
using namespace std;
list<string> fill(int n);
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
    l.list_ins(l2,3);
    cout<<l.print()<<" "<<l.get_size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<l.print()<<" "<<l.get_size()<<endl;
    cout<<l.find("str4")<<endl;
    cout<<l.find("gio")<<endl;
    list<string> l3 = l;
    cout<<l3.print()<<" "<<l3.get_size()<<endl;
    l3 = l2;
    cout<<l3.print()<<" "<<l3.get_size()<<endl;
    l3 = fill(5);
    cout<<l3.print()<<" "<<l3.get_size()<<endl;
    list<string> l4 = fill(7);
    cout<<l4.print()<<" "<<l4.get_size()<<endl;
    list<string> l5 = l4 + l3;
    cout<<l5.print()<<l5.get_size()<<endl;
    vector<string> vec = {"Mele", "Pere","Pomodori"};
    l5 = l2 + to_list(vec);
    cout<<l5.print()<<l5.get_size()<<endl;
    l3 = l4.extractlist(3,1);
    cout<<l3.print()<<" "<<l3.get_size()<<endl;
    cout<<l4.print()<<" "<<l4.get_size()<<endl;
    l4.list_ins(l3,3);
    cout<<l4.print()<<" "<<l4.get_size()<<endl;
    l3 = l4.extractlist(-1,1);
    cout<<l3.print()<<" "<<l3.get_size()<<endl;
    cout<<l4.print()<<" "<<l4.get_size()<<endl;
    l4.list_ins(l3,-1);
    cout<<l4.print()<<" "<<l4.get_size()<<endl;
}
list<string> fill(int n){
    string s = "fill";
    list<string> l;
    for(int i=0;i<n;i++){
        l.push_back(s + to_string(i));
    }
    return l;
}