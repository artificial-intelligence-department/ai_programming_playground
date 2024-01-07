#include <iostream>
#include <string>
#include <cmath>

// Функція для обчислення найменшої довжини поля для банера з прізвищем
double calculateMinFieldLength(const std::string& surname) {
    int vowelsCount = 0;

    // Розрахунок кількості голосних букв у прізвищі
    for (char letter : surname) {
        char lowercaseLetter = tolower(letter);
        if (lowercaseLetter == 'a' || lowercaseLetter == 'e' || lowercaseLetter == 'i' ||
            lowercaseLetter == 'o' || lowercaseLetter == 'u' ) {
            vowelsCount++;
        }
    }

    const double widthPerVowel = vowelsCount * 0.8; // Ширина банера залежно від кількості голосних букв

    // Повернення мінімальної довжини поля для банера з прізвищем
    return widthPerVowel;
}

int main() {
    std::string surname = " litovinskiy "; 

    // Обчислення найменшої довжини поля для банера з прізвищем
    double minFieldLength = calculateMinFieldLength(surname);

    std::cout << "Minimum field length required for a banner with your surname: " << minFieldLength << " meters" << std::endl;

    // Визначення символів прізвища, які будуть розміщені на центральних трьох метрах поля
    int totalChars = surname.length();

    // При написанні зліва направо
    std::cout << "Characters on the central 3 meters when written from left to right: ";
    for (int i = 0; i < totalChars; ++i) {
        if (i * 0.8 >= minFieldLength - 3.0 && i * 0.8 <= minFieldLength) {
            std::cout << surname[i] << " ";
        }
    }
    std::cout << std::endl;

    // При написанні справа наліво
    std::cout << "Characters on the central 3 meters when written from right to left: ";
    for (int i = totalChars - 1; i >= 0; --i) {
        if ((totalChars - i - 1) * 0.8 >= minFieldLength - 3.0 && 
            (totalChars - i - 1) * 0.8 <= minFieldLength) {
            std::cout << surname[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
