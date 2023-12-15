#include <iostream>
#include <vector>

using namespace std;

// Функція для перевірки, чи послідовність символів є паліндромом
bool isPalindrome(const vector<char>& sequence, int start, int end) {
    // Базовий випадок: якщо послідовність має один або нуль символів, вона є паліндромом
    if (start >= end) {
        return true;
    }

    // Рекурсивний виклик: порівняння першого та останнього символів та перехід до наступної підстроки
    return (sequence[start] == sequence[end]) && isPalindrome(sequence, start + 1, end - 1);
}

int main() {
    // Введення послідовності символів
    cout << "Enter the symbols: "<<endl;
    string input;
    getline(cin, input);

    // Конвертація рядка в вектор символів
    vector<char> charSequence(input.begin(), input.end());

    // Перевірка, чи послідовність є паліндромом
    if (isPalindrome(charSequence, 0, charSequence.size() - 1)) {
        cout << "The input is a palindrome" << endl;
    } else {
        cout << "The input is not a palindrome" << endl;
    }

    return 0;
}
