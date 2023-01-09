#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;
void fill(auto start, auto end);
int main(){
    vector<char> vec(20);
    fill(vec.begin(), vec.end());
    cout << find(vec.begin(),vec.end(),'17')<<endl;
}
void fill(auto start, auto end){
    for(int i = 0;start + i !=end; i++){
        start[i] = i + 1;
    }
}