#include <iostream>
#include <cstring>
using namespace std;

void rwords(char* str) {
    int length = strlen(str);

    
    auto reverse = [](char* start, char* end) { //функція яка обиртає послідовність символів в масиві
        while (start < end) {
            swap(*start, *end); //Обиртає рядок
            start++; // право
            end--;  // Ліво
        }
    };

    
    reverse(str, str + length - 1); //обиртає всю строку

    // Обертаємо кожне слово
    char* start = str;
    char* end = str;
    while (*end) { //нульовий символ
        if (*end == ' ') { // Перевірка пробілу
            reverse(start, end - 1); //обертаємо слово між 
            start = end + 1; //наступне слово 
        }
        end++; 
    }

    
    reverse(start, end - 1); // Обертаємо останнє слово

}

int main() {
    const int maxLength = 256;
    char input[maxLength];

    cout << "Введіть рядок: ";
    cin.getline(input, maxLength); //збереження рядка

 
    rwords(input);

    
    cout << "Результат: " << input << endl; //результат

    return 0;
}
   