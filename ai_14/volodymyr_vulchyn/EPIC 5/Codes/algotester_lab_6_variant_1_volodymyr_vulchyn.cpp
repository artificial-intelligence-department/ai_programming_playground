#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // Введення кількості слів та мінімальної кількості входжень
    int totalWords, threshold;
    cin >> totalWords >> threshold;

    // Створення словника для визначення частоти кожного слова
    map<string, int> wordFrequency;

    // Зчитування слів та підрахунок їх кількості
    vector<string> words(totalWords);
    for (int i = 0; i < totalWords; ++i) {
        cin >> words[i];

        // Перетворення слова у нижній регістр
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);

        // Збільшення лічильника кількості входжень слова
        wordFrequency[words[i]]++;
    }

    // Вибір букв, які належать словам, які зустрічаються не менше K разів
    set<char> uniqueLetters;
    for (const auto &word : words) {
        if (wordFrequency[word] >= threshold) {
            for (const char &letter : word) {
                uniqueLetters.insert(letter);
            }
        }
    }

    // Вивід результату
    if (uniqueLetters.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << uniqueLetters.size() << endl;

        // Вивід унікальних букв у зворотньому алфавітному порядку
        for (auto it = uniqueLetters.rbegin(); it != uniqueLetters.rend(); ++it) {
            cout << *it;

            // Додавання пробіла між буквами (крім останньої)
            if (next(it) != uniqueLetters.rend()) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
