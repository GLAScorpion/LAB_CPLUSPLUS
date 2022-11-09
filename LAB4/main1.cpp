#include <iostream>
#include <string.h>
using namespace std;
bool is_palindrome(const string& s);
int main(){
    string s;
    cout << "Inserire stringa\n";
    cin >> s;
    cout << s << " = " << is_palindrome(s) << endl;
}
bool is_palindrome(const string& s){
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i]!=s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}
