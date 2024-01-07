#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int amount_of_letters = 1;
    string compressed_string;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == s[i + 1]) {
            amount_of_letters++;
        } 
        else {
            compressed_string += to_string(amount_of_letters);
            amount_of_letters = 1;
        }
    }

    cout << compressed_string;

    return 0;
}


