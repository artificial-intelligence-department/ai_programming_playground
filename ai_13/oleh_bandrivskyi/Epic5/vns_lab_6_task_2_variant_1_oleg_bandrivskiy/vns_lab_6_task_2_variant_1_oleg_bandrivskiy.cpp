#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool isIdentifier(const char* word) {

    for (int i = 0; word[i] != '\0'; ++i) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    const int maxChars = 255;
    char inputString[maxChars];

    cout << "Введіть рядок: ";
    cin.getline(inputString, maxChars);

    char* token = strtok(inputString, " ");
    while (token != nullptr) {
        if (isIdentifier(token)) {
            cout << token << " ";
        }
        token = strtok(nullptr, " ");
    }


    return 0;
}
