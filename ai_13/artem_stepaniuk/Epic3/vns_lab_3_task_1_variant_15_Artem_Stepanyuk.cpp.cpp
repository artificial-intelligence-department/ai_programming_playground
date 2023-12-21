#include <iostream>
#include <cstdarg>

int octToDecimal(int count, ...) {
    va_list args;
    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; ++i) {
        int octalNumber = va_arg(args, int);

        int decimalNumber = 0;
        int base = 1;

        while (octalNumber > 0) {
            int lastDigit = octalNumber % 10;
            decimalNumber += lastDigit * base;
            octalNumber /= 10;
            base *= 8;
        }

        result += decimalNumber;
    }

    va_end(args);

    return result;
}

int main() {
    int result1 = octToDecimal(3, 15, 23, 37);
    std::cout << "Result 1: " << result1 << std::endl;

    int result2 = octToDecimal(6, 10, 20, 30, 40, 50, 60);
    std::cout << "Result 2: " << result2 << std::endl;

    int result3 = octToDecimal(7, 1, 2, 3, 4, 5, 6, 7);
    std::cout << "Result 3: " << result3 << std::endl;

    return 0;
}