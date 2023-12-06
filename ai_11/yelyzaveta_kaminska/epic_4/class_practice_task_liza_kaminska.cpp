#include <iostream>
#include <string>

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

bool isPalindrome(int number) {
    string strNumber = to_string(number);

    return isPalindrome(strNumber, 0, strNumber.length() - 1);
}

int main() {
    string word;
    cout << "Enter some word: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }

    int number;
    cout << "Enter some number: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << number << " is palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
