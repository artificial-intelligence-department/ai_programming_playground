#include <iostream>
#include <vector>

int main() {
    std::vector<int> sides(5);

    // Введення сторін кубів
    std::cout << "Введи сторони кубів a1 a2 a3 a4 a5 ";
    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> sides[i])) {
            std::cerr << "ERROR: Помилка введення\n";
            return 1;
        }

        // Перевірка обмежень
        if (sides[i] < 0 || sides[i] > 1e12) {
            std::cerr << "ERROR: Сторона куба має бути в межах від 0 до 10^12\n";
            return 1;
        }
    }
    
         // Перевірка можливості поставити куб
    for (int i = 1; i < 5; ++i) {
        if (sides[i - 1] < sides[i]) {
            std::cout << "LOSS\n";
            return 1;
        }
    }

    // Якщо ти дойшов сюди, ти переміг
    std::cout << "WIN\n";

    return 0;
}