#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void sortCharsInWords(char* str) {
    int len = strlen(str);

    // Проходимо по кожному символу рядка
    for (int i = 0; i < len; i++) {
        // Якщо знайдено початок слова
        if (isalpha(str[i])) {
            // Знаходимо кінцевий індекс слова
            int j = i;
            while (isalpha(str[j + 1])) {
                j++;
            }

            // Сортуємо букви між початковим і кінцевим індексами слова
            sort(str + i, str + j + 1);

            // Пересуваємо індекс до кінця слова
            i = j;
        }
    }
}

int main() {
    const int MAX_LENGTH = 255;
    char str[MAX_LENGTH];

    cout << "Enter a string: ";
    cin.getline(str, MAX_LENGTH);

    // Виклик функції для сортування букв в кожному слові
    sortCharsInWords(str);

    cout << "Converted string: " << str << endl;

    return 0;
}