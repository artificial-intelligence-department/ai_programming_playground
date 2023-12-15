#include <iostream>

// Перевантажена функція для ділення десяткових дробів
double divide(double a, double b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero.\n";
        return 0.0;  // Повертаємо 0 у разі помилки
    }
    return a / b;
}

// Перевантажена функція для ділення звичайних дробів
struct Fraction {
    int numerator;
    int denominator;
};

Fraction divide(const Fraction& a, const Fraction& b) {
    if (b.numerator == 0) {
        std::cerr << "Error: Division by zero.\n";
        Fraction result = {0, 0};  // Повертаємо 0/0 у разі помилки
        return result;
    }

    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;

    return result;
}

int main() {
    // Ділення десяткових дробів
    double decimalResult = divide(10.5, 2.0);
    std::cout << "Результат ділення десяткових дробів: " << decimalResult << std::endl;

    // Ділення звичайних дробів
    Fraction fractionA = {3, 4};//це 0,75 : 0.5
    Fraction fractionB = {1, 2};

    Fraction fractionResult = divide(fractionA, fractionB);
    std::cout << "Результат ділення звичайних дробів: " << fractionResult.numerator << "/" << fractionResult.denominator << std::endl;

    return 0;
}
