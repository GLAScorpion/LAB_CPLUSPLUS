#include <iostream>
#include "myvector.h"
using namespace std;
vector fill(int num);
int main(void){
    vector a (7);
    cout << a.size() << endl;
    a[2] = 3.2;
    vector b = a;
    cout << a << " "<< b<<endl;
    vector c (8);
    c[7] = {4.5};
    c[6] = {3.0};
    cout << c <<endl;
    c = b;
    cout << c << endl;
    vector d = fill(10);
    cout << d <<endl;
    vector e = {3.3 , 4.5 , 665 , 7.6};
    cout << e <<endl;
    e = fill(3);
    cout<<e<<endl;

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