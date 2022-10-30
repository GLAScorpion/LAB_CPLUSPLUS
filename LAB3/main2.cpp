#include <iostream>

void print_array_length(int* ar);

int main(){
    const int l = 10;
    int ar[l];
    std::cout<< sizeof(ar) << "\n";
    print_array_length(ar);
}
void print_array_length(int* array){
    std::cout<< sizeof(array) << "\n"; //essendo la variabile array un puntatore al primo elemento dell'array sizeof trova 8 come dimensione
                                       // cioè la dimensione di un puntatore, non di un array di int
}