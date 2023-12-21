#include <iostream>
#include <cstdarg>
#include <cmath>
using namespace std;

void dToT(int num, ...) {
    va_list ptr;
    va_start(ptr, num);

    for (; num > 0; num--) {
        int n = 0;
        int numX = va_arg(ptr, int);
        int temp = numX;

        cout << numX << " -> ";

        while (temp > 0) {
            temp /= 3;
            n++;
        }

        int t[n];
        int res[n];

        for (int i = 0; numX > 0; i++) {
            t[i] = numX % 3;
            numX /= 3;
        }

        for (int i = 0; i < n; i++) {
            res[i] = t[n - 1 - i];
            cout << res[i];
        }
        cout << "; ";
    }
    cout << endl;
    va_end(ptr);
}

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void convert(double decimal) {
    const int precision = 10000;

    int numerator = static_cast<int>(decimal * precision);
    int denominator = precision;

    int gcd = findGCD(numerator, denominator);

    numerator /= gcd;
    denominator /= gcd;

    cout << "Десятковий дріб " << decimal << " у звичайному вигляді: " << numerator << "/" << denominator << endl;
}

void convert(int numerator, int denominator) {
    cout << "Звичайний дріб " << numerator << "/" << denominator << " у десятковому вигляді: " << static_cast<double>(numerator) / denominator << endl;
}

int main() {
    dToT(3, 21, 8, 30);
    dToT(4, 56, 2, 32, 44);
    dToT(7, 33, 11, 18, 64, 126, 256, 512);
    
    double decimal;

    cout << "Введіть десятковий дріб: ";
    cin >> decimal;
    convert(decimal);

    int numerator, denominator;

    cout << "Введіть чисельник звичайного дробу: ";
    cin >> numerator;
    cout << "Введіть знаменник звичайного дробу: ";
    cin >> denominator;
    convert(numerator, denominator);
    return 0;
}
