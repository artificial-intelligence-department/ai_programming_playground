#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

// Convert a string to lowercase
std::string toLowerCase(const std::string& str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

// Function to sort a string in descending order
void sortString(std::string& str) {
    std::sort(str.begin(), str.end(), std::greater<char>());
}

std::string countWords(const std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> wordCount;

    // Count occurrences of each word
    for (const std::string& word : words) {
        std::string lowercaseWord = toLowerCase(word);
        wordCount[lowercaseWord]++;
    }

    std::vector<std::string> resultWords;

    // Include words that occur more than or equal to k times
    for (const auto& entry : wordCount) {
        if (entry.second >= k) {
            resultWords.push_back(entry.first);
        }
    }

    if (resultWords.empty()) {
        return "Empty!";
    }

    // Sort the resultWords in descending order
    for (std::string& word : resultWords) {
        sortString(word);
    }

    // Concatenate the resultWords into a single string with spaces
    std::string resultStr;
    std::unordered_set<char> addedChars;
    int countof_1=0;

    for (const std::string& word : resultWords) {
        for (char symbol : word) {
            // Output each unique lowercase symbol only once
            char lowercaseSymbol = std::tolower(symbol);
            if (addedChars.find(lowercaseSymbol) == addedChars.end()) {
                resultStr += lowercaseSymbol;
                resultStr += ' ';
                countof_1++;
                addedChars.insert(lowercaseSymbol);
            }
        }
    }

    return std::to_string(countof_1) + "\n" + resultStr;
}

int main() {
    long int n, k;
    std::cin >> n >> k;

    std::vector<std::string> words(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    std::cout << countWords(words, k) << std::endl;

    return 0;
}
