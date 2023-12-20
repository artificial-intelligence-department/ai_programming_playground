#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool isVowel(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countConsonants(const std::string& word) {
    int consonantCount = 0;
    for (char c : word) {
        if (std::isalpha(c) && !isVowel(c)) {
            consonantCount++;
        }
    }
    return consonantCount;
}

int main() {
    std::ofstream file1("C:\\Users\\MAHINA\\Desktop\\MyE5\\F1.txt");
    if (!file1.is_open()) {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }

    std::vector<std::string> words;
    std::cout << "Enter 10 words:\n";
    for (int i = 0; i < 10; ++i) {
        std::string word;
        std::cin >> word;
        file1 << word << "\n";
        words.push_back(word);
    }
    file1.close();

    std::ifstream file2("C:\\Users\\MAHINA\\Desktop\\MyE5\\F1.txt");
    if (!file2.is_open()) {
        std::cerr << "Unable to open file for reading.\n";
        return 1;
    }

    std::string firstWord;
    file2 >> firstWord;
    file2.close();

    int consonantCount = countConsonants(firstWord);
    std::cout << "Consonant count in the first word (" << firstWord << "): " << consonantCount << "\n";

    std::ofstream file3("C:\\Users\\MAHINA\\Desktop\\MyE5\\F2.txt");
    if (!file3.is_open()) {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }

    bool foundDuplicate = false;
    for (const std::string& word : words) {
        if (word == firstWord) {
            if (!foundDuplicate) {
                foundDuplicate = true;
                continue;
            }
        }
        file3 << word << "\n";
    }
    file3.close();

    return 0;
}
