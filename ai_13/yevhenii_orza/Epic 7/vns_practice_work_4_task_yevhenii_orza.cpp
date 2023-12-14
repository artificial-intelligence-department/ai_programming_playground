#include <iostream>



int main() {

    // Виведення квадратів перших п'яти цілих позитивних непарних чисел
    for (int i = 1; i <= 10; i += 2) {
        std::cout << i << "\t" << i * i << "\n";
    }

    return 0;
}
