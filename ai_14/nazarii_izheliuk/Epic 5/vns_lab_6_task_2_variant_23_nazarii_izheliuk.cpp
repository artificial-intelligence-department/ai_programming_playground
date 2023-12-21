#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string FindMinWord(string input) {
    istringstream iss(input);
    string word;
    string min_word;

    min_word = string(input.length(), ' ');

    while (iss >> word) {
        if (word.length() < min_word.length()) {
            min_word = word;
        }
    }

    return min_word;
}

int main() {
    string input;
    cout << "Введіть рядок: ";
    getline(cin, input);

    cout << "Найкоротше слово: " << FindMinWord(input);

    return 0;
}
