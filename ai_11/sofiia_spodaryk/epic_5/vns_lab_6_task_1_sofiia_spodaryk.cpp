#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputString;
    cout << "Введіть рядок: ";
    getline(cin, inputString);

    string longestWord;
    size_t maxLength = 0;
    size_t wordStart = 0;

    for (size_t i = 0; i <= inputString.length(); ++i) {
        if (i == inputString.length() || inputString[i] == ' ') {
            size_t wordLength = i - wordStart;

            if (wordLength > maxLength) {
                maxLength = wordLength;
                longestWord = inputString.substr(wordStart, wordLength);
            }

            wordStart = i + 1;
        }
    }

    cout << "Довжина найдовшого слова: " << maxLength << endl;
    cout << "Найдовше слово: " << longestWord << endl;

    return 0;
}
