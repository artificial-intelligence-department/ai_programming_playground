#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void sortLettersInWords(string& str) {
    // Розділити рядок на слова
    size_t start = 0, end = 0;
    while ((end = str.find(' ', start)) != string::npos) {
        // Сортувати букви в слові
        sort(str.begin() + start, str.begin() + end);
        start = end + 1;
    }

    // Сортувати букви в останньому слові або єдиному слові
    sort(str.begin() + start, str.end());
}

int main() {
    const int max_length = 255;
    char s[max_length];

    cout << "Введіть рядок (не більше 255 символів): ";
    
    gets(s);

    // Перетворення рядка
    string str(s);
    sortLettersInWords(str);

    // Виведення результату
    cout << "Результат: " << str << "." << endl;

    return 0;
}
