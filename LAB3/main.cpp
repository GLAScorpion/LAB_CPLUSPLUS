#include <iostream>
#include "myvector.h"
using namespace std;
vector fill(int num);
int main(void){
    vector a (7);
    cout << a.get_size() << endl;
    a[2] = 3.2;
    vector b = a;
    cout << a << " "<< b<<endl;
    vector c (8);
    c[7] = {4.5};
    c[6] = {3.0};
    c = b;
    cout << c << endl;
    vector d = fill(10);
    cout << d <<endl;
}
vector fill(int num){
    vector vec (num);
    for(double i = 0; i< num;i++){
        if(i == 0){
            vec[i] = 1;
        }else{
            vec[i] = i+1/(i);
        }
    }
    return vec;
}