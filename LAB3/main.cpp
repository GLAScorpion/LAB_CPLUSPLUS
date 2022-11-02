#include <iostream>
#include "myvector.h"
using namespace std;
int main(void){
    vector a {7};
    int c {2};
    cout << a.get_size() << endl;
    a[c] = 3.2;
    cout << a[c] << " " << a[3] << endl;
    a[6] = 3.0;
}