#include <iostream>
using namespace std;
bool is_palindrome(const char* first, const char* last);
int main(){
    string sa;
    cout << "Inserire stringa\n";
    cin >> sa;
    char s1[sa.length() + 1];
    for(int i = 0; i < sa.length(); i++){
        s1[i] = sa[i];
    }
    s1[sa.length()] ='\0';
    char* p = s1;
    cout << sa <<" = " << is_palindrome(&p[0], &p[sa.length()-1]) << endl;
}
bool is_palindrome(const char* first, const char* last){
    int counter = 0;
    while(&first[counter] < &last[-counter]){
        if(first[counter] !=last[-counter]){
            return false;
        }
        counter ++;
    }
    return true;
}