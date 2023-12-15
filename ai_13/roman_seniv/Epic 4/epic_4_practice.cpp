#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input_str;
    cout << "Enter a string: ";
    cin >> input_str;

    const char* input_cstr = input_str.c_str();

    if (isPalindrome(input_str)) {
        cout << "String is a palindrome." << endl;
    } else {
        cout << "String is not a palindrome." << endl;
    }


    return 0;
}
