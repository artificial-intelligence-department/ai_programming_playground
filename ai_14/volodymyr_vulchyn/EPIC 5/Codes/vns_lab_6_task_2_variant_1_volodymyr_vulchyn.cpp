#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Функція для сортування цифр у слові за спаданням
void descendNum(char* word) { 
    int length = strlen(word);

    for (int i = 0; i < length; ++i) {
        if (isdigit(word[i])) {
            int j = i;
            
            while (isdigit(word[j])) {
                ++j;
            }

            // Функція, яка відсортовує послідовність символів у слові в порядку спадання.
            sort(word + i, word + j, greater<char>()); // Тобто, ми вказуємо на діапазон символів у слові, які відповідають спадній послідовності цифр.

            i = j; // Пропускаємо вже відсортовані цифри та перейти до наступної частини рядка для подальшої обробки.
        }
    }
}

int main() {
    const int strLength = 255;
    char strInput[strLength];

    cout << "Enter the line of nubmers: " << endl;
    cin.getline(strInput, strLength);

    char* token = strtok(strInput, " ");
    while (token != nullptr) { // Це цикл, який виконується, при отриманні нового токена. (Та превіряє чи присутні слова у рядку)
        descendNum(token);
        cout << token << " ";
        token = strtok(nullptr, " ");
    }

    return 0;
}
