#include <iostream>
#include <cstdarg>

int min(int x, ...);

int main() {
    int minOf5, minOf10, minOf12;

    minOf5 = min(5, 3, 17, 6, 5, 0);
    minOf10 = min(10, 2, 4, 3, 17, 34, 5, 7, -4, 8, 22);
    minOf12 = min(12, 3, 6, 9, 13, 22, 11, 6, 45, 1, 7, 5, 16);

    std::cout << "minOf5 = " << minOf5 << std::endl;
    std::cout << "minOf10 = " << minOf10 << std::endl;
    std::cout << "minOf12 = " << minOf12 << std::endl; 

    return 0;
}

int min(int x, ...) {
    va_list args;
    va_start(args, x);
    int minimalValue = va_arg(args, int);

    for(int i = 0; i <= x; i++){
        int argument = va_arg(args, int);

        if(argument < minimalValue) {
            minimalValue = argument;
        }
    }

    va_end(args);

    return minimalValue;
}