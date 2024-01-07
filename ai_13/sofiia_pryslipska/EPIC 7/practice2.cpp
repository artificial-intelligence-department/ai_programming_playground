#include <iostream>
#include <string>

using namespace std;

int main() {
    string surname = "Pryslipska";
    int vowelCount = 0; // Використана цілочисельна змінна

    
    // використаний for цикл для обчислення кількості голосних букв у прізвищі
    for (char letter : surname) {
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u' || tolower(letter) == 'y') {
            vowelCount++;
        }
    }

    // Обчислюємо ширину букви
    float letterWidth = vowelCount * 0.8; // Використана дійсна змінна

    // Обчислюємо мінімальну довжину банера
    float minBannerLength = letterWidth * surname.length();
// використано оператори виведення та введення даних

    cout << "The minimum length of the banner for placing the surname 'Pryslipska': " << minBannerLength << " metres" << endl;

    
    int centralStart = (surname.length() - 3) / 2;
    int centralEnd = centralStart + 3;

    cout << "Symbols on 3 central meters ( left to right): ";
    for (int i = centralStart; i < centralEnd; ++i) { // використаний for цикл для знаходження символів на 3-х центральних метрах поля
        cout << surname[i];
    }
    cout << endl;

    cout << "Symbols on 3 central meters (right to left): ";
    for (int i = centralEnd - 1; i >= centralStart; --i) {
        cout << surname[i];
    }
    cout << endl;

    return 0;
}


