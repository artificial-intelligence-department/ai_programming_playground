#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

int main() {
    std::string word;
    std::cin >> word;

    std::unordered_set<char> letters;

    for (char letter : word) {
        letters.insert(letter);
    }

    std::cout << letters.size() << std::endl;

    return 0;
}