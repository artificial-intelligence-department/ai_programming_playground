#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &str, size_t start, size_t end) {
    if (start >= end) {
        return true;
    }

    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string word_to_check;
    cout << "Enter word: ";
    cin >> word_to_check;

    if (isPalindrome(word_to_check, 0, word_to_check.length() - 1)) {
        cout << word_to_check << "\t" << "Yes, it is" << endl;
    } 
    else {
        cout << word_to_check << "\t" << "No, it isnt" << endl;
    }

    return 0;
}
