#include <iostream>
#include <vector>
#include <algorithm>
bool cmp(int& x);
using namespace std;
int main(){
    vector<int> vec = { 2, 5 , 6, 8, 10, 20, 3 , 56, 77};
    int pnt = *find_if(vec.begin(), vec.end(), cmp);
    cout << pnt<<endl;
}
bool cmp(int& x){
    int* pnt = &x;
    return x > pnt[1];
}
