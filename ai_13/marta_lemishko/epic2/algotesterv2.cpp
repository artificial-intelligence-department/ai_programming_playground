#include <iostream>

int main() {
    int h[4], d[4];

    std::cout << "Введіть довжини ніжок стола (h1 h2 h3 h4): ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> h[i];
    }

    std::cout << "Введіть довжини, які відпиляють від відповідних ніжок (d1 d2 d3 d4): ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> d[i];
    }

    int minHeight = h[0];

    for (int i = 0; i < 4; ++i) {
        if (d[i] > h[i]) {
            std::cout << "ERROR" << std::endl;
            return 0;
        }

        if (h[i] < minHeight) {
            minHeight = h[i];
        }
    }

    if (minHeight * 2 <= h[0]) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
