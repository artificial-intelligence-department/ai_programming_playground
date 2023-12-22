#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include<algorithm>

using namespace std;

    /*
    Задано рядок, що складається із символів. Символи поєднуються в слова.
    Слова одне від одного відокремлюються одним або декількома пробілами.
    Наприкінці тексту ставиться крапка. Текст містить не більше 255 символів.
    Виконати ввід рядка, використовуючи функцію gets(s) і здійснити обробку
    рядка у відповідності зі своїм варіантом.
    Перетворити рядок таким чином, щоб на його початку були записані слова,
    що містять тільки цифри, потім слова, що містять тільки букви, а потім слова,
    які містять і букви і цифри.
    */

const int MAX_LENGTH = 255;

void processString(char s[]) {
    char digits[MAX_LENGTH] = "";
    char letters[MAX_LENGTH] = "";
    char mixed[MAX_LENGTH] = "";

    char *token = strtok(s, " ");
    while (token != nullptr) {
        bool hasDigit = false;
        bool hasLetter = false;

        for (int i = 0; i < strlen(token); ++i) {
            if (isdigit(token[i])) {
                hasDigit = true;
            } else if (isalpha(token[i])) {
                hasLetter = true;
            }
        }

        if (hasDigit && !hasLetter) {
            strcat(digits, token);
            strcat(digits, " ");
        } else if (!hasDigit && hasLetter) {
            strcat(letters, token);
            strcat(letters, " ");
        } else if (hasDigit && hasLetter) {
            strcat(mixed, token);
            strcat(mixed, " ");
        }

        token = strtok(nullptr, " ");
    }

    strcat(digits, letters);
    strcat(digits, mixed);

    // Вивід результату
    cout << digits << "." << endl;
}

int main() {
    char input[MAX_LENGTH];
    
    cout << "Введіть рядок: ";
    gets(input);

    processString(input);

    return 0;
}

