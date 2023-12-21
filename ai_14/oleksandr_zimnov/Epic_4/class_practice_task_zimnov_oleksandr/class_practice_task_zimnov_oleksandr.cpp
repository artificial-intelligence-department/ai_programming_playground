#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    }
    else {
        return false;
    }
}
bool isPalindrome(int number) {
    string numStr = to_string(number);
    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() {
    string word;
    cout << "Enter your word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "It`s palindrome."<<endl;
    }
    else {
        cout << "It isn`t palindrome."<<endl;
    }

    int number;
    cout << "Enter your number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << "It`s palindrome."<<endl;
    }
    else {
        cout << "It isn`t palindrome."<<endl;
    }

    return 0;
}