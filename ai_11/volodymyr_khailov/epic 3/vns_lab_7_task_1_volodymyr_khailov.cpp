#include <iostream>
#include <cstdarg>

using namespace std;

// Структура для представлення звичайного дробу
struct Fraction {
    long long numerator;
    long long denominator;
};

// Фунуція для знаходження НСД
long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функція для знаходження суми звичайних дробів
Fraction sumFractions(int count, ...) {
    Fraction result = {0, 1};  // Ініціалізація суми як 0/1

    va_list args;
    va_start(args, count);

    for (long long i = 0; i < count; ++i) {
        Fraction fraction = va_arg(args, Fraction);

        // Обчислення суми
        result.numerator = result.numerator * fraction.denominator + fraction.numerator * result.denominator;
        result.denominator *= fraction.denominator;
    }

    va_end(args);
    
    // Знаходження НСД для скорочення дробу
    long long gcd = gcdll(result.numerator, result.denominator);
    // Скорочення дробу за допомогою НСД
    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}

// Функція для виводу змішаного числа
void printMixedNumber(Fraction result) {
    long long wholePart = result.numerator / result.denominator;
    long long remainder = result.numerator % result.denominator;

    cout << wholePart;
    if (remainder != 0) {
        cout << " " << remainder << "/" << result.denominator;
    }
}

int main() {
    // Виклик функції sum для звичайних дробів з різною кількістю аргументів
    Fraction fraction1 = {1, 2};
    Fraction fraction2 = {1, 3};
    Fraction fraction3 = {2, 5};
    Fraction fraction4 = {3, 7};
    Fraction fraction5 = {4, 9};
    Fraction fraction6 = {5, 11};
    Fraction fraction7 = {6, 13};
    Fraction fraction8 = {7, 15};
    Fraction fraction9 = {8, 17};
    Fraction fraction10 = {9, 19};
    Fraction fraction11 = {10, 21};
    Fraction fraction12 = {11, 23};

    Fraction resultFraction1 = sumFractions(3, fraction1, fraction2, fraction3);
    Fraction resultFraction2 = sumFractions(5, fraction4, fraction5, fraction6, fraction7, fraction8);
    Fraction resultFraction3 = sumFractions(12, fraction1, fraction2, fraction3, fraction4, fraction5, fraction6, fraction7, fraction8, fraction9, fraction10, fraction11, fraction12);
    
    // Виведення результату для звичайних дробів
    cout << "Result 1: ";
    printMixedNumber(resultFraction1);
    cout << endl;

    cout << "Result 2: ";
    printMixedNumber(resultFraction2);
    cout << endl;

    cout << "Result 3: ";
    printMixedNumber(resultFraction3);
    cout << endl;

    return 0;
}
