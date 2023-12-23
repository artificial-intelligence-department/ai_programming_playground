#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }

    // перевірка символів
    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    // конвертація цілого числа в рядок
    string str = to_string(number);


    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << " word is palindrome." << endl;
    } else {
        cout << "word is not  palindrome." << endl;
    }

    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << "integer is palindrome." << endl;
    } else {
        cout << " integer is not palindrome." << endl;
    }

    return 0;
}