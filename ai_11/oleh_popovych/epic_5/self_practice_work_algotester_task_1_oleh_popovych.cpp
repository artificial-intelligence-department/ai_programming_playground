//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>
#include <unordered_map>
#include <set>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::unordered_map<std::string, int> wordCount;

    std::string word;
    for (int i = 0; i < N; i++) {
        std::cin >> word;
        for(char& j : word) {
            j = tolower(j);
        }

        wordCount[word]++;
    }

    auto cmp = [](char a, char b) { return a > b; };
    std::set<char, decltype(cmp)> resultLetters(cmp);

    for (const auto& pair : wordCount) {
        if (pair.second >= K) {
            std::set<char> uniqueLetters(pair.first.begin(), pair.first.end());

            for (char letter : uniqueLetters) {
                resultLetters.insert(letter);
            }
        }
    }

    if (resultLetters.empty()) {
        std::cout << "Empty!" << std::endl;
    } else {
        std::cout << resultLetters.size() << std::endl;
        for (char letter : resultLetters) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
