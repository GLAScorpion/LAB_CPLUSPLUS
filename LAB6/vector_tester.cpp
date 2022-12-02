#include <iostream>
#include "myvector.h"
void fill(vector<int>& vec);
void fill_to_cap(vector<int>& vec);
using namespace std;
int main(){
    vector<int> a;
    cout << a.size() <<" "<<a.capacity()<<endl;
    vector<int> b = vector<int>(20);
    cout << b.size() <<" "<<b.capacity()<<endl;
    b.reserve(30);
    cout << b.size() <<" "<<b.capacity()<<endl;
    b.reserve(29);
    cout << b.size() <<" "<<b.capacity()<<endl;
    fill(b);
    cout << b <<endl;
    cout<<"At(10): "<<b.at(10)<<endl;
    vector<int> c = {1 , 3 ,7, 20 , 74};
    cout << c <<c.size() <<" "<< c.capacity()<<endl;
    c.push_back(33);
    cout << c << c.size() <<" " << c.capacity()<<endl;
    cout << c.pop_back() << " " << c << c.size() <<" " << c.capacity()<<endl;
    fill_to_cap(c);
    cout << c << c.size() <<" " << c.capacity()<<endl;
    c.push_back(69);
    cout << c << c.size() <<" " << c.capacity()<<endl;
    
}
void fill(vector<int>& vec){
    for(int a = 0; a < vec.size(); a++){
        vec[a] = a +1;
    }
}
void fill_to_cap(vector<int>& vec){
    for(int a = vec.size(); a < vec.capacity(); a++){
        vec.push_back(a + 1);
    }
}