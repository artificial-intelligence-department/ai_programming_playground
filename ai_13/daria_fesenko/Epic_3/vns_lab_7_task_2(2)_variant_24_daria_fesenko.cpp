#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
using namespace std;

void remove_words(string &str) {
    istringstream iss(str);
    ostringstream oss;

    string word;
    unordered_set<string> uniqueWords;
    int removedWordCount = 0;

    while (iss >> word) {
        if (word.length() % 2 != 0) {
            if (uniqueWords.find(word) == uniqueWords.end()) {
                uniqueWords.insert(word);
                oss << word << " ";
            } else {
                removedWordCount++;
            }
        } else {
            oss << word << " ";
        }
    }

    cout << "Видалено парних слів: " << removedWordCount << endl;
    str = oss.str();
}

int main() {
    string str;
    cout << "Введіть рядок слів: ";
    getline(cin, str);

    remove_words(str);

    cout << "Рядок без повторюваних парних слів: " << str << endl;

    return 0;
}
