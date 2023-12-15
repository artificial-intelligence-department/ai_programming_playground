#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string sComp;
 
    int amount=1;
    int a=0;
    while (a+1<s.length()) {
        if (s[a] == s[a+1]) {
            ++amount;
        } else {
            sComp += s[a];
            if (amount>1) {
                sComp += to_string(amount);
            }
            amount = 1;
        }

        ++a;
    }
    sComp += s.back();
    if (amount>1) {
        sComp += to_string(amount);
    }
    cout << sComp;
}
