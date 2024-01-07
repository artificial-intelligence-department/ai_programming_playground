#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& W, int start, int end) {
    // Базовий випадок: якщо початок рівний кінцю, то це паліндром
    if (start == end) {
        return true;
    }

    // Рекурсивний виклик: порівняння символів на поточній позиції
    if (W[start] != W[end]) {
        return false;
    }

    // Рекурсивний виклик для наступної пари символів
    return isPalindrome(W, start + 1, end - 1);
}

// Перевантажена функція для перевірки, чи ціле число є паліндромом
bool isPalindrome(int num) {
    // Перетворення цілого числа на рядок
    string numW = to_string(num);

    // Виклик рекурсивної функції для рядка
    return isPalindrome(numW, 0, numW.length() - 1);
}

int main() {
    // Приклади використання

    string word = "radar";
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "\"" << word << "\"Palindrom" << endl;
    } else {
        cout << "\"" << word << "\"Not palindrom" << endl;
    }
    
    int number = 12321;
    if (isPalindrome(number)) {
        cout << number << "Palindrom" << endl;
    } else {
        cout << number << "Not palindrom" << endl;
    }

    number = 12345;
    if (isPalindrome(number)) {
        cout << number << "Palindrom" << endl;
    } else {
        cout << number << "Not Palindrom" << endl;
    }

    return 0;
}
