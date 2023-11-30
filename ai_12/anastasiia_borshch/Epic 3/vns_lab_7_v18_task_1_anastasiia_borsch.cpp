#include <iostream>
#include <cstdarg> 

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int nok(int first, ...) {
    int result = first;
    va_list args;
    va_start(args, first);

    int next = va_arg(args, int);
    while (next != -1) {
        result = lcm(result, next);
        next = va_arg(args, int);
    }

    va_end(args);
    return result;
}

int main() {
    
    int result1 = nok(3, 5, 6, -1);
    std::cout << "NSK for 3, 5, 6: " << result1 << std::endl;

    
    int result2 = nok(10, 15, 25, 5, 8, -1);
    std::cout << "NSK for 10, 15, 25, 5, 8: " << result2 << std::endl;

    
    int result3 = nok(7, 14, 21, 28, 35, 42, -1);
    std::cout << "NSK for 7, 14, 21, 28, 35, 42: " << result3 << std::endl;

    return 0;
}
