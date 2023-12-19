#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    // Базовий випадок: коли початок перевищує кінець
    if (start >= end) {
        return true;
    }

    // Рекурсивний крок: перевіряємо, чи символи в початковій та кінцевій позиціях збігаються
    if (str[start] != str[end]) {
        return false;
    }

    // Рекурсивний крок: раптом збігається, переходимо до наступних позицій
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    // Перетворення числа на рядок
    string str = to_string(number);

    // Використовуємо рядкову версію функції, щоб перевірити, чи є рядок паліндромом
    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    string input;
    cout << "Enter a word or number: ";
    cin >> input;

    bool palindrome;

    // Перевірка, чи введений рядок є паліндромом
    palindrome = isPalindrome(input, 0, input.length() - 1);
    if (palindrome) {
        cout << input << " is a palindrome." << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }

    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Перевірка, чи введене число є паліндромом
    palindrome = isPalindrome(number);
    if (palindrome) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}