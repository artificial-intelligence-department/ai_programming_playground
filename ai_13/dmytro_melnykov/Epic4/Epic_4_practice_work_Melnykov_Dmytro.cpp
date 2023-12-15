#include <iostream>
#include <string>


bool isPalindrome(const std::string& str, int firstind, int endind) { // перевірка чи рядок є паліндромом
    
    if (firstind >= endind) {   //якщо початок перевищив кінець, рядок є паліндромом
        return true;
    }

    if (str[firstind] == str[endind]) { //порівнюємо символи спочатку і в кунці

        return isPalindrome(str, firstind + 1, endind - 1); // Рекурсія, виклик для наступної пари символів
    }
    return false;
}

// Перевантажена функція чи ціле число є паліндромом
bool isPalindrome(int number) {
    
    std::string str = std::to_string(number);

    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    std::string word;
    std::cout << "Введіть слово або число: ";
    std::cin >> word;

    // Виклик рекурсивної функції для рядка
    if (isPalindrome(word, 0, word.length() - 1)) {
        std::cout << "Це слово або число є паліндромом.\n";
    } else {
        std::cout << "Це слово або число не є паліндромом.\n";
    }

    return 0;
}
