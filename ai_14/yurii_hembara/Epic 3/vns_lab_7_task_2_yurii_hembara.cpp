#include <iostream>

// Клас для представлення комплексних чисел
class Complex {
public:
    double real;
    double imaginary;

    Complex(double r, double i) : real(r), imaginary(i) {}

    // Перевантаження оператору /
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double realPart = (real * other.real + imaginary * other.imaginary) / denominator;
        double imagPart = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(realPart, imagPart);
    }

    // Виведення комплексного числа
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real << " + " << complex.imaginary << "i";
        return os;
    }
};

// Перевантаження функції ділення для цілих чисел
int divide(int a, int b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return 0;
    }
    return a / b;
}

// Перевантаження функції ділення для комплексних чисел
Complex divide(const Complex& a, const Complex& b) {
    if (b.real == 0 && b.imaginary == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Complex(0, 0);
    }
    return a / b;
}

int main() {
    // Ділення цілих чисел
    int resultInt = divide(10, 2);
    std::cout << "Result of integer division: " << resultInt << std::endl;

    // Ділення комплексних чисел
    Complex complex1(4, 2);
    Complex complex2(2, 1);
    Complex resultComplex = divide(complex1, complex2);
    std::cout << "Result of complex division: " << resultComplex << std::endl;

    return 0;
}
