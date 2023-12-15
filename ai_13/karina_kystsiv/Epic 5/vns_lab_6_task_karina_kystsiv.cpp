#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    const int maxStringLength = 255;
    char s[maxStringLength];

    std::cout << "Input string: \n";
    std::cin.getline(s, maxStringLength);

    std::stringstream ss(s);
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) {
        if (std::isdigit(word[0])) {
            words.push_back(word);
        }
    }

    std::sort(words.rbegin(), words.rend());

    std::cout << "Sorted:\n";
    for (const auto& w : words) {
        std::cout << w << " ";
    }

    return 0;
}