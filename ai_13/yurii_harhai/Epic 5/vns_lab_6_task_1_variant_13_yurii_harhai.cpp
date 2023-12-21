#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isNumber(char );
bool sortDescending(char, char);

int main() {
    string str;
    cout << "Enter row: ";
    getline(cin, str);

    string word;
    for (char c : str) {
        if (isalnum(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                sort(word.begin(), word.end(), sortDescending);
                cout << word;
                word = "";
            }
            cout << c;
        }
    }

    if(!word.empty()) {
        sort(word.begin(), word.end(), sortDescending);
        cout << word;
    }

    return 0;
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

bool sortDescending(char a, char b) {
    if (isNumber(a) && isNumber(b)) {
        return a > b;
    }
    return false;
}