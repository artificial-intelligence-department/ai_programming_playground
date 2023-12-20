#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void sortDigitsDescending(char *word) {

    int digitCount = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isdigit(word[i])) {
            digitCount++;
        }
    }

    if (digitCount <= 1) {
        return;
    }

    int *digitIndices = new int[digitCount];
    int currentIndex = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isdigit(word[i])) {
            digitIndices[currentIndex++] = i;
        }
    }

    for (int i = 0; i < digitCount - 1; i++) {
        for (int j = 0; j < digitCount - i - 1; j++) {
            if (word[digitIndices[j]] < word[digitIndices[j + 1]]) {
                char temp = word[digitIndices[j]];
                word[digitIndices[j]] = word[digitIndices[j + 1]];
                word[digitIndices[j + 1]] = temp;
            }
        }
    }

    delete[] digitIndices;
}

int main() {
    const int maxLength = 255;
    char inputString[maxLength];

    cout << "Введіть рядок (не більше " << maxLength - 1 << " символів): ";
    cin.getline(inputString, maxLength);

    char *token = strtok(inputString, " ");
    while (token != nullptr) {
        sortDigitsDescending(token);

        cout << token << " ";

        token = strtok(nullptr, " ");
    }

    cout << "." << endl;

    return 0;
}
