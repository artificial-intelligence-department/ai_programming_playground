#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string inputText;
    cout << "Введіть текст:\n";
    getline(cin, inputText); // Отримуємо введений текст

    stringstream ss(inputText);
    string word;
    vector<string> longestWords;
    int maxLength = 0;

    cout << "Слова у тексті:\n";

    while (ss >> word) { // Розділяємо текст на слова
        cout << word << endl;

        // Знаходимо найдовші слова
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWords.clear();
            longestWords.push_back(word);
        } else if (word.length() == maxLength) {
            longestWords.push_back(word);
        }
    }

    cout << "Найдовші слова:\n";
    for (const auto &longestWord : longestWords) {
        cout << longestWord << " (довжина " << maxLength << " символів)\n";
    }

    return 0;
}