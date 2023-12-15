#include <iostream>

using namespace std;

// Структура для представлення звичайного дробу
struct Fraction {
    long numerator;
    long denominator;
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

// Перевантажена функція для множення звичайних дробів
Fraction multiply(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.numerator;
    result.denominator = fraction1.denominator * fraction2.denominator;

    // Знаходження НСД для скорочення дробу
    long long gcd = gcdll(result.numerator, result.denominator);
    // Скорочення дробу за допомогою НСД
    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}

// Перевантажена функція для множення десяткових дробів float або double
template <typename T>
T multiply(const T& num1, const T& num2) {
    return num1 * num2;
}

int main() {
    // Приклад для множення десяткових дробів
    double decimalResult = multiply(3.14, 2.5);
    cout << "а) Результат множення десяткових дробів: " << decimalResult << endl;

    // Приклад для множення звичайних дробів
    Fraction fraction1 = {3, 4};  
    Fraction fraction2 = {2, 3};  
    Fraction fractionResult = multiply(fraction1, fraction2);
    cout << "б) Результат множення звичайних дробів: " << fractionResult.numerator << "/" << fractionResult.denominator << endl;

    return 0;
}



