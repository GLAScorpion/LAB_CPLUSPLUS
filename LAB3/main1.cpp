#include <iostream>
void f(void);
void printar(int* ar, int l);
void f_illegal(void);
int main(void){
    f();
    f_illegal();
}
void f(void){
    const int l {10};
    int array[l];
    int* punt = array + 3;
    for(int i = -3; i < l - 3; i ++){
        punt[i] = i; 
    }
    printar(array,l);
}
void printar(int* ar, int l){
    for(int a = 0; a < l; a++){
        std::cout << ar[a] << " ";
    }
    std::cout << "\n";
}
void f_illegal(){
    const int l {10};
    const int cycles {100};
    int array[l];
    int* punt = array + 3;
    for(int i = -3; i < cycles ; i ++){
        std::cout << i << "\n";
        punt[i] = i; 
    }
    std::cout << "\n";
}