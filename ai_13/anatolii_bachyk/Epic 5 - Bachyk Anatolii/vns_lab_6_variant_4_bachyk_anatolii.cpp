#include <iostream>
#include <cstring>

using namespace std;

void printMatchingWords(const char *input) {
    char inputCopy[256]; // Створення копії введеного рядка, оскільки функція strtok модифікує вхідний рядок
    strcpy(inputCopy, input);

    char *firstWord = strtok(inputCopy, " "); // Отримання першого слова

    cout << "Слова, які співпадають з першим словом '" << firstWord << "':" << endl;

    char *word;
    while ((word = strtok(NULL, " ")) != NULL) { // Отримання інших слів та їх порівняння з першим словом
        if (strcmp(word, firstWord) == 0) {
            cout << word << endl;
        }
    }
}

int main() {
    cout << "Введіть рядок тексту (не більше 255 символів) з крапкою в кінці:" << endl;

    char input[256];
    cin.getline(input, sizeof(input)); // Введення рядка тексту

    printMatchingWords(input); // Виклик функції для обробки та виведення слів

    return 0;
}