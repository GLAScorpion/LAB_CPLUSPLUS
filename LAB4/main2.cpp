#include <iostream>
#include <string.h>
using namespace std;
bool is_palindrome(const char s[], int length);
int main(){
    string sa;
    cout << "Inserire stringa\n";
    cin >> sa;
    char s1[sa.length() + 1];
    for(int i = 0; i < sa.length(); i++){
        s1[i] = sa[i];
    }
    s1[sa.length()] ='\0';
    cout << sa <<" = " << is_palindrome(s1,sa.length()) << endl;
}
bool is_palindrome(const char s[], int length){
    for(int i = 0; i < length / 2; i++){
        if(s[i]!=s[length-i -1]){
            return false;
        }
    }
    return true;
}