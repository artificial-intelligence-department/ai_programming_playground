#include <iostream>
#include <string>

using namespace std;

// Рекурсивна функція для перевірки, чи рядок є паліндромом
bool isPalindrome(const string& str, int start, int end) {
    // Базовий випадок: якщо початок перевищує кінець, то рядок є паліндромом
    if (start >= end) {
        return true;
    }

    // Перевіряємо, чи символи на поточних позиціях збігаються
    if (str[start] != str[end]) {
        return false;
    }

    // Рекурсивний виклик для наступних позицій
    return isPalindrome(str, start + 1, end - 1);
}

// Перевантажена функція для цілих чисел
bool isPalindrome(int number) {
    // Перетворюємо ціле число на рядок
    string strNumber = to_string(number);

    // Використовуємо рядкову версію функції isPalindrome для перевірки, чи це паліндром
    return isPalindrome(strNumber, 0, strNumber.length() - 1);
}

int main() {
    // Введення слова або числа від користувача
    cout << "Введіть слово або число: ";
    string input;
    cin >> input;

    // Перевірка, чи введений рядок є паліндромом
    if (isPalindrome(input, 0, input.length() - 1)) {
        cout << input << " - є паліндромом." << endl;
    } else {
        cout << input << " - не є паліндромом." << endl;
    }

    return 0;
}
