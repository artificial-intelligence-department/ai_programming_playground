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

bool isPalindrome(int num) {
    string str = to_string(num);

    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {     // Перевірка, чи введене слово є паліндромом
        cout << "The word is a palindrome." << endl;
    } else {
        cout << "The word is not a palindrome." << endl;
    }

    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Перевірка, чи введене число є паліндромом
    if (isPalindrome(number)) {
        cout << "The number is a palindrome." << endl;
    } else {
        cout << "The number is not a palindrome." << endl;
    }

    return 0;
}
