#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
void remove_even_words(char *s) {
    char result[256] = "";  // для зберігання зміненого рядка
    char *token;  // для розбиття рядка на слова
    int count = 0;  // лічильник для слів

    // Розбиваємо рядок на слова
    token = strtok(s, " ");
    while (token != NULL) {
        count++;

        // Якщо номер слова парний, пропускаємо його
        if (count % 2 != 0) {
            strcat(result, token);
            strcat(result, " ");  // додаємо пробіл після кожного слова
        }

        token = strtok(NULL, " ");  // отримуємо наступне слово
    }

    // Видаляємо останній пробіл і додаємо крапку
    result[strlen(result) - 1] = '.';
    strcpy(s, result);
}

int main() {
    char s[256];

    cout<<("Vvedit' ryadok (ne bil'she 255 symboliv): ");
    gets(s);

    remove_even_words(s);

    cout<<("Zminenyj ryadok: %s\n", s);

    return 0;
}