#include <iostream>
#include <string>
#include <cctype>

// Рекурсивна функція для рядків
bool isPalindrome(const std::string& str, int start, int end) {
    // Базовий випадок: якщо початок перевищує кінець, то це паліндром
    if (start >= end) {
        return true;
    }

    // Ігнор неалфавітних символів
    while (start < end && !std::isalpha(str[start])) {
        start++;
    }
    while (start < end && !std::isalpha(str[end])) {
        end--;
    }

    // Порівнюємо символи на поточних позиціях (без врахування регістру)
    if (std::tolower(str[start]) != std::tolower(str[end])) {
        return false;
    }

    // Рекурсивний виклик для наступної пари символів
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    // Введення слова від користувача
    std::string userInput;
    std::cout << "Enter word: ";
    std::cin >> userInput;

    // Перевірка, чи введене слово є паліндромом
    if (isPalindrome(userInput, 0, userInput.length() - 1)) {
        std::cout << "\"" << userInput << "\" is palindrome." << std::endl;
    } else {
        std::cout << "\"" << userInput << "\" is not palindrome." << std::endl;
    }

    return 0;
}
