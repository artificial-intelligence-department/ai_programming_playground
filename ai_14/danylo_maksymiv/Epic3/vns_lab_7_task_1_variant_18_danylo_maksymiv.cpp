#include <iostream>
#include <cstdarg>

using namespace std;

int findGCD(int number1, int number2) {
    while (number1 > 0 && number2 > 0) {
        if (number1 > number2) {
            number1 %= number2;
        } else {
            number2 %= number1;
        }
    }
    return number1 + number2;
}

int findLCM(int k, ...) {
    int lcm = 1;
    va_list args;
    va_start(args, k);

    for (; k != 0; k--) {
        int num = va_arg(args, int);
        int gcd = findGCD(lcm, num);
        lcm = (lcm * num) / gcd;
    }

    va_end(args);
    return lcm;
}

int main() {
    int result1 = findLCM(3, 2, 3, 4);
    int result2 = findLCM(4, 5, 10, 15, 20);
    int result3 = findLCM(5, 7, 14, 21, 28, 35);

    cout << "НСК для 2, 3, та 4: " << result1 << endl;
    cout << "НСК для 5, 10, 15, та 20: " << result2 << endl;
    cout << "НСК для 7, 14, 21, 28, та 35: " << result3 << endl;

    return 0;
}
