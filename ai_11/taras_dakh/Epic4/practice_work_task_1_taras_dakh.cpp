#include <iostream>
#include <string>
#include <algorithm>

// Рекурсивна функція для перевірки, чи рядок є паліндромом
bool isPalindrome(const std::string& str, int start, int end) {
    //  якщо початок рівний кінецю, рядок є паліндромом
    if (start >= end) {
        return true;
    }

    // Рекурсивний крок: порівнюємо символи на початку та в кінці рядка
    if (str[start] != str[end]) {
        return false; // Якщо символи не співпадають, рядок не є паліндромом
    }

    // Рекурсивно перевіряємо наступні позиції
    return isPalindrome(str, start + 1, end - 1);
}

// Перевантажена функція для перевірки, чи ціле число є паліндромом
bool isPalindrome(int num) {
    // Перетворюємо ціле число на рядок
    std::string numStr = std::to_string(num);

    // Викликаємо рядкову версію функції isPalindrome для перевірки паліндрому
    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() {
    // Введення рядка для перевірки паліндрому
    std::cout << "Введіть рядок: ";
    std::string inputStr;
    std::getline(std::cin, inputStr);

    // Перевірка рядка
    if (isPalindrome(inputStr, 0, inputStr.length() - 1)) {
        std::cout << "\"" << inputStr << "\" є паліндромом." << std::endl;
    } else {
        std::cout << "\"" << inputStr << "\" не є паліндромом." << std::endl;
    }

    // Введення цілого числа для перевірки паліндрому
    std::cout << "Введіть ціле число: ";
    int inputNum;
    std::cin >> inputNum;

    // Перевірка цілого числа
    if (isPalindrome(inputNum)) {
        std::cout << inputNum << " є паліндромом." << std::endl;
    } else {
        std::cout << inputNum << " не є паліндромом." << std::endl;
    }

    return 0;
}