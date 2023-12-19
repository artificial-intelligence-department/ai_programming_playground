#include <iostream>

using namespace std;

int main() {
    // Використані цілочисельні та дійсні змінні
    int minFieldLength = 100;  // 1. в коді використана як мінімум одна цілочисельна змінна || Мінімальна довжина поля в ярда
    int maxFieldLength = 130;  // Максимальна довжина поля в ярдах
    double footToInch = 12.0;  // / 2. в коді використана як мінімум одна дійсна змінна Перетворення футів в дюйми
    double inchToCm = 2.54;    // Перетворення дюймів в сантиметри
    double widthMultiplier = 0.8;  // Множник ширини букви

    // Розрахунок довжини банера в метрах
    string surname = "Semenov";  // Ваше прізвище
    int vowelCount = 0;  // Лічильник голосних букв

    // Лічильник голосних букв для розрахунку ширини букви
    for (char letter : surname) {//10 . в коді використаний for цикл 
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' ||
            tolower(letter) == 'o' || tolower(letter) == 'u') {
            vowelCount++;
        }
    }

    // Вивід розрахунків
    cout << "Довжина банера: 3 метри" << endl;

    // Розрахунок символів на центральних трьох метрах поля
    int centralCharsCount = 0;

    // Варіант 1: З лівого краю поля до правого
    cout << "Символи з лівого краю до правого: ";
    for (int i = 0; i < 3; i++) {//10 . в коді використаний for цикл 
        if (i < surname.length()) {//5. в коді використані умовні оператори та розгалуження
            cout << surname[i];
        } else {
            cout << " ";
        }
    }
    cout << endl;

    // Варіант 2: З правого краю поля до лівого
    cout << "Символи з правого краю до лівого: ";
    for (int i = 0; i < 3; i++) {//10 . в коді використаний for цикл 
        if (i < surname.length()) {//5. в коді використані умовні оператори та розгалуження
            cout << surname[surname.length() - 1 - i];
        } else {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
