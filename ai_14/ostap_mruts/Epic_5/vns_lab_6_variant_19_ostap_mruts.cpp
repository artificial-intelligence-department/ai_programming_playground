#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

bool isIdentifier(const std::string& word) {
    if (word.empty() || !isalpha(word[0]) && word[0] != '_') {
        return false;
    }

    for (size_t i = 1; i < word.length(); ++i) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return false;
        }
    }

    return true;
}

int main() {
    std::istringstream iss("slovo _slovo_ slovechko-s slovo123 _slovo 1slovechko");
    std::string word;
    bool isFirstWord = true;

    while (iss >> word) {
        if (isIdentifier(word)) {
            if (!isFirstWord) {
                std::cout << ' ';
            }
            std::cout << word;
            isFirstWord = false;
        }
    }

    std::cout << "." << std::endl;

    return 0;
}