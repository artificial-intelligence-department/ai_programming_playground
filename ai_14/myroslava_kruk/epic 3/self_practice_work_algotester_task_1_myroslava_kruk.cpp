#include <iostream>

int main() {
    // Введення кількості апельсинів у Марічки, Софійки і Петрика
    long long a, b, c;
    std::cin >> a >> b >> c;

    // Перевірка, чи Марічка та Софійка разом мають більше апельсинів, ніж Петрик
    if (a + b > c) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
