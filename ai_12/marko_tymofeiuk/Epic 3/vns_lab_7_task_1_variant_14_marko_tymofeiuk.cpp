#include <iostream>
#include <cstdarg>
#include <cmath>

void binaryToTernary(int num, ...) {
    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; i++) {
        int number = va_arg(args, int);
        int j = 0, value = 0;

        // Converting binary to decimal
        while (number != 0) {
            int remainder = number % 10;
            value += remainder * pow(2, j);
            j++;
            number /= 10;
        }

        // Converting decimal to ternary
        int terval = 0, x = 0;
        while (value != 0) {
            int trirem = value % 3;
            terval += trirem * pow(10, x);
            x++;
            value /= 3;
        }

        std::cout << terval << " ";
    }

    va_end(args);
    std::cout << std::endl;
}

int main() {
    binaryToTernary(3, 1101, 1010, 111000);
    binaryToTernary(6, 11, 100110, 10101, 110010, 11101, 1010);
    binaryToTernary(7, 101100, 111, 110111, 10001, 110011, 1110, 101010);
}
