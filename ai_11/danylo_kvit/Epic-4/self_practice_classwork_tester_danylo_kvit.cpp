#include "self_practice_classwork_danylo_kvit.cpp"
#include <iostream>
using namespace std;
int main(){
    string s;
    long long n = 0;
    cin >> s;
    bool is_int=true;
    for(int i=0;i<s.size();i++) {
        if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' &&
            s[i] != '7' && s[i] != '8' && s[i] != '9') {
            is_int = false;
            break;
        }
        else{
            n = n*10;
            n+=(s[i]- to_string(0)[0]);
        }
    }
    char* x = &s[0];
    if(is_int){if(is_pal(n)) cout << "Yes\n";else cout << "No(int)\n";}
    else if(is_pal(x,s.size())) cout << "Yes\n";else cout << "No(str)\n";
}