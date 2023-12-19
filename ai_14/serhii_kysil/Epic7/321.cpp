#include <iostream>
#include <string>
#include <cmath>

int main() {
    // Визначення прізвища та кількості голосних букв
    std::string surname;
    std::cin >> surname;
    int numVowels = 0; // пункт 1
    for (char letter : surname) {
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
            letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'y' || letter == 'Y') {
            numVowels++;
        }
    }

    // Розрахунок ширини букви
    double letterWidth = numVowels * 0.8; // пункт 3

    // Довжина поля у метрах
    double fieldLength = 118.872; 

    // Визначення проміжку для написання
    double writingSpace = 3.0; // метри

    double bannerLength = surname.length() * letterWidth;

    std::cout << bannerLength << std::endl;

    // Визначення кількості символів, які можуть вміститися в проміжку
    int numCharacters = std::ceil(writingSpace / letterWidth);

    // Визначення символів на 3-х центральних метрах поля
    int centralStart = static_cast<int>((fieldLength - writingSpace) / 2.0);
    int centralEnd = centralStart + numCharacters;

    // Виведення символів на 3-х центральних метрах поля
    for (int i = centralStart; i < centralEnd; i++) {// пункт 10
        std::cout << surname[i % surname.length()];
    }
    std::cout << std::endl;

    return 0;
}
