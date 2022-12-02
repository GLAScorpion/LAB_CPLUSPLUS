#include <iostream>
#include <vector>
#include <algorithm>
template <typename T>
bool cmp(T& x);
using namespace std;
int main(){
    vector<int> vec = { 2, 5 , 6, 8, 10, 20, 3 , 56, 77};
    auto pnt = find_if(vec.begin(), vec.end(), cmp<int>);
    cout << pnt[0] << endl;
}
template<typename T>
bool cmp(T& x){
    T* pnt = &x;
    return x > pnt[1];
}
