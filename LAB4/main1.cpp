#include <iostream>
#include <string.h>
using namespace std;
bool is_palindrome(const string& s);
int main(){
    string a = "anna";
    string b = "annna";
    string c = "alba";
    cout << a << " = " << is_palindrome(a) << endl;
    cout << b << " = " << is_palindrome(b) << endl;
    cout << c << " = " << is_palindrome(c) << endl;
}
bool is_palindrome(const string& s){
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i]!=s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}
