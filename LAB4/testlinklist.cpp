#include <iostream>
#include "linklist.h"
#include <vector>
using namespace std;
list<string> fill(int n);
int main(){
    list<string> l = {"str1", "str2", "str3"};
    cout <<"list l\n"<< l.print()<<" "<<l.size()<<endl;
    l.push_back("str4");
    l.push_front("str5");
    cout<<"push back: str4, push front: str5\n"<<l.print()<<" "<<l.size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<"pop back, pop front\n"<<l.print()<<" "<<l.size()<<endl;
    l[1] = "pino";
    cout<<"string pino a index 1\n"<<l.print()<<" "<<l.size()<<endl;
    l.remove(1);
    cout<<"remove index 1\n"<<l.print()<<" "<<l.size()<<endl;
    l.remove(1);
    cout<<"remove index 1\n"<<l.print()<<" "<<l.size()<<endl;
    l.remove(0);
    cout<<"remove index 0\n"<<l.print()<<" "<<l.size()<<endl;
    l.push_front("str4");
    cout<<l.print()<<" "<<l.size()<<endl;
    l.push_back("str5");
    cout<<l.print()<<" "<<l.size()<<endl;
    l.ins_before("hello",1);
    l.ins_after("ciao",2);
    cout<<"ins before index 1 of string hello, ins after index 2 of string ciao\n"<<l.print()<<" "<<l.size()<<endl;
    list<string> l2 = {"c++", "java","python"};
    cout<<"list l2\n"<<l2.print()<<" "<<l2.size()<<endl;
    l.list_ins(l2,3);
    cout<<"list ins of l2 in l at index 3\n"<<l.print()<<" "<<l.size()<<endl;
    l.pop_back();
    l.pop_front();
    cout<<"pop back and pop front of l\n"<<l.print()<<" "<<l.size()<<endl;
    cout<<"Is string ciao in l? At which index?: "<<l.find("ciao")<<endl;
    cout<<"Is string gio in l? At which index?: "<<l.find("gio")<<endl;
    list<string> l3 = l;
    cout<<"test copy constructor\n"<<l3.print()<<" "<<l3.size()<<endl;
    l3 = l2;
    cout<<"test copy operator\n"<<l3.print()<<" "<<l3.size()<<endl;
    l3 = fill(5);
    cout<<"test move operator\n"<<l3.print()<<" "<<l3.size()<<endl;
    list<string> l4 = fill(7);
    cout<<"test move constructor\n"<<l4.print()<<" "<<l4.size()<<endl;
    list<string> l5 = l4 + l3;
    cout<<"l4 + l3:\n"<<l5.print()<<l5.size()<<endl;
    vector<string> vec = {"Mele", "Pere","Pomodori"};
    l5 = l2 + to_list(vec);
    cout<<"test to_list(): l2 + to_list(vec): \n"<<l5.print()<<l5.size()<<endl;
    l3 = l4.extractlist(3,1);
    cout<<"exctract from list l4 from index 3 to 1 more element\n"<<l3.print()<<" "<<l3.size()<<endl;
    cout<<l4.print()<<" "<<l4.size()<<endl;
    l4.list_ins(l3,2);
    cout<<"re insertion of exctracted list in l4\n"<<l4.print()<<" "<<l4.size()<<endl;
    l3 = l4.sublist(1,1);
    cout<<"sublist of l4 from index 1 for 1 more element\n"<<l3.print()<<" "<<l3.size()<<endl;
    cout<<l4.print()<<" "<<l4.size()<<endl;
    vector<string> vec2 = to_vector(l2);
    cout<<"test of to_vector on l2\n";
    for(int i = 0; i<vec2.size();i++){
        cout<<vec2[i]<<" ";
    }
    cout<<endl<<"size (bytes) of list with different templates: \n";
    cout<<sizeof(l4)<<endl;
    cout<<sizeof(list<string>)<<endl;
    cout<<sizeof(list<long long int>)<<endl;
}
list<string> fill(int n){
    string s = "fill";
    list<string> l;
    for(int i=0;i<n;i++){
        l.push_back(s + to_string(i));
    }
    return l;
}