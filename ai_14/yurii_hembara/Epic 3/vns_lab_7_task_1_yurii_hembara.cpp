#include <iostream>
#include <cstdarg>

// Функція min зі змінною кількістю параметрів
template <typename T>
T findMin(int count, ...) {
    va_list args;
    va_start(args, count);

    T minVal = va_arg(args, T);
    for (int i = 1; i < count; ++i) {
        T val = va_arg(args, T);
        if (val < minVal) {
            minVal = val;
        }
    }

    va_end(args);

    return minVal;
}

int main() {
    // Виклики функції min для int
    int minInt1 = findMin<int>(5, 3, 1, 7, 2, 5);
    int minInt2 = findMin<int>(10, 8, 12, 5, 3, 17, 4, 6, 10, 1, 9);
    int minInt3 = findMin<int>(12, 15, 11, 8, 7, 14, 2, 9, 6, 12, 10, 5, 3);

    // Виклики функції min для double
    double minDouble1 = findMin<double>(5, 3.5, 1.2, 7.8, 2.3, 5.6);
    double minDouble2 = findMin<double>(10, 8.1, 12.4, 5.7, 3.2, 17.6, 4.9, 6.3, 10.2, 1.8, 9.5);
    double minDouble3 = findMin<double>(12, 15.7, 11.3, 8.9, 7.2, 14.6, 2.1, 9.4, 6.8, 12.5, 10.3, 5.9, 3.1);

    // Виведення результатів
    std::cout << "Min int 1: " << minInt1 << std::endl;
    std::cout << "Min int 2: " << minInt2 << std::endl;
    std::cout << "Min int 3: " << minInt3 << std::endl;
    std::cout << "Min double 1: " << minDouble1 << std::endl;
    std::cout << "Min double 2: " << minDouble2 << std::endl;
    std::cout << "Min double 3: " << minDouble3 << std::endl;

    return 0;
}
