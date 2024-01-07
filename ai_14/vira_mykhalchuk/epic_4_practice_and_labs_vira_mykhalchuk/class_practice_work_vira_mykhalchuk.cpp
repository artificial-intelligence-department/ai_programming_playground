#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {

    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {

    string numStr = to_string(num);


    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() {

    string word;
    cout << "Enter your word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is a palidrome.\n";
    } else {
        cout << word << " isn't a palindrome.\n";
    }

    int number;
    cout << "Enter your number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " is a palidrome.\n";
    } else {
        cout << number << " isn't a palidrome.\n";
    }

    return 0;
}