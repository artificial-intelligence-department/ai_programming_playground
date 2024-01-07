#include <iostream>
#include <cmath>

int kvadr(int numbers[], int count) {
    int result = 0; // змінна для обчислення кількості квадратів

    for (int i = 0; i < count; ++i) {
        int num = numbers[i];
        if (sqrt(num) == floor(sqrt(num))) { // перевіряє, чи є число є точним квадратом
            result++;
        }
    }

    return result;
}

int main() {
    // Виклик функції kvadr для 3 параметрів
    int n1[] = {1, 4, 5};
    int result1 = kvadr(n1, 3);
    std::cout << "Для 3 параметрів: " << result1 << " числа є точними квадратами." << std::endl;

    // Виклик функції kvadr для 7 параметрів
    int n2[] = {16, 25, 36, 49, 50, 64, 81};
    int result2 = kvadr(n2, 7);
    std::cout << "Для 7 параметрів: " << result2 << " числа є точними квадратами." << std::endl;

    // Виклик функції kvadr для 11 параметрів
    int n3[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121};
    int result3 = kvadr(n3, 11);
    std::cout << "Для 11 параметрів: " << result3 << " числа є точними квадратами." << std::endl;

    return 0;
}
