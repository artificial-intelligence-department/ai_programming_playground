#include <iostream>
#include <algorithm>
#include <string>

std::string sortLettersInWords(const std::string& input) {
    // Розділити рядок на слова
    std::string result;
    std::string word;

    for (char ch : input) {
        if (ch == ' ') {
            // Сортувати букви у слові і додати його до результату
            std::sort(word.begin(), word.end());
            result += word + ' ';
            word = "";
        } else {
            word += ch;
        }
    }

    // Сортувати букви у останньому слові і додати його до результату
    std::sort(word.begin(), word.end());
    result += word;

    return result;
}

int main() {
    // Приклад використання
    std::string input = "ACDF BOAB MAD312";
    std::string result = sortLettersInWords(input);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Sorted  : " << result << std::endl;

    return 0;
}
