#include <iostream>
void print_reference(const int& var1, const double& var2);
void print_pointer(int* var1, double* var2);
using namespace std;

int main(){
    int var1 {10};
    double var2 {13.5};
    print_reference(var1,var2);
    print_pointer(&var1, &var2);
}
void print_reference(const int& var1, const double& var2){
    cout << "var1: " << var1 << " var2: " << var2 << endl;
}
void print_pointer(int* var1, double* var2){
    cout << "var1: " << *var1 << " var2: " << *var2 << endl;
}