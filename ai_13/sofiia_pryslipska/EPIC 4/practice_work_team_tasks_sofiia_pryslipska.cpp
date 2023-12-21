

#include <iostream>
#include <string>
#include <algorithm> // Для використання функції reverse() для рядків
using namespace std;


// Функція для перевірки, чи рядок є паліндромом
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

// Перевантажена функція для перевірки, чи ціле число є паліндромом
bool isPalindrome(int num) {
    string strNum = to_string(num); // Перетворення числа в рядок
    return isPalindrome(strNum, 0, strNum.length() - 1);
}

int main() {
    string word;
    int number;

    // Перевірка для рядка
    cout << "enter a word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "\"" << word << "\" is a palindrom." << endl;
    } else {
        cout << "\"" << word << "\"is not a palindrom." << endl;
    }

    // Перевірка для цілого числа
    cout << "enter a number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << "\"" << number << "\" is a palindrom." << endl;
    } else {
        cout << "\"" << number << "\" is not a palindrom." << endl;
    }

    return 0;
}


 
