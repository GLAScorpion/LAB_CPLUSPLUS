#include <iostream>
#include "linklist.h"
#include <vector>
using namespace std;
list<string> fill(int n);
int main(){
    list<string> l = {"str1", "str2", "str3"};
    cout << l.print()<<" "<<l.size()<<endl;
    l.push_back("str4");
    l.push_front("str5");
    cout<<l.print()<<" "<<l.size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<l.print()<<" "<<l.size()<<endl;
    l[1] = "pino";
    cout<<l.print()<<" "<<l.size()<<endl;
    l.remove(1);
    cout<<l.print()<<" "<<l.size()<<endl;
    l.remove(1);
    cout<<l.print()<<" "<<l.size()<<endl;
    l.remove(0);
    cout<<l.print()<<" "<<l.size()<<endl;
    l.push_front("str4");
    cout<<l.print()<<" "<<l.size()<<endl;
    l.push_back("str5");
    cout<<l.print()<<" "<<l.size()<<endl;
    l.ins_before("hello",1);
    l.ins_after("ciao",2);
    cout<<l.print()<<" "<<l.size()<<endl;
    list<string> l2 = {"c++", "java","python"};
    l.list_ins(l2,3);
    cout<<l.print()<<" "<<l.size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<l.print()<<" "<<l.size()<<endl;
    cout<<l.find("str4")<<endl;
    cout<<l.find("gio")<<endl;
    list<string> l3 = l;
    cout<<l3.print()<<" "<<l3.size()<<endl;
    l3 = l2;
    cout<<l3.print()<<" "<<l3.size()<<endl;
    l3 = fill(5);
    cout<<l3.print()<<" "<<l3.size()<<endl;
    list<string> l4 = fill(7);
    cout<<l4.print()<<" "<<l4.size()<<endl;
    list<string> l5 = l4 + l3;
    cout<<l5.print()<<l5.size()<<endl;
    vector<string> vec = {"Mele", "Pere","Pomodori"};
    l5 = l2 + to_list(vec);
    cout<<l5.print()<<l5.size()<<endl;
    l3 = l4.extractlist(3,1);
    cout<<l3.print()<<" "<<l3.size()<<endl;
    cout<<l4.print()<<" "<<l4.size()<<endl;
    l4.list_ins(l3,2);
    cout<<l4.print()<<" "<<l4.size()<<endl;
    l3 = l4.extractlist(-1,1);
    cout<<l3.print()<<" "<<l3.size()<<endl;
    cout<<l4.print()<<" "<<l4.size()<<endl;
    l4.list_ins(l3,-1);
    cout<<l4.print()<<" "<<l4.size()<<endl;
    l3 = sublist(l4,-1,1);
    cout<<l3.print()<<" "<<l3.size()<<endl;
    cout<<l4.print()<<" "<<l4.size()<<endl;
    vector<string> vec2 = to_vector(l2);
    for(int i = 0; i<vec2.size();i++){
        cout<<vec2[i]<<" ";
    }
    cout<<endl;
}
list<string> fill(int n){
    string s = "fill";
    list<string> l;
    for(int i=0;i<n;i++){
        l.push_back(s + to_string(i));
    }
    return l;
}