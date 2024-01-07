#include <iostream>

double multiplyDecimals(double num1, double num2) {
    return num1 * num2;
}

void simplifyFraction(int& numerator, int& denominator) {
    int gcd = 1;
    for (int i = 1; i <= numerator && i <= denominator; ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }
    numerator /= gcd;
    denominator /= gcd;
}

void multiplyFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen) {
    resultNum = num1 * num2;
    resultDen = den1 * den2;
    simplifyFraction(resultNum, resultDen);
}

int main() {
    int numerator1, denominator1, numerator2, denominator2;
    double num1, num2;
    int menu;
    
    do {
        std::cout << "1. Множення десяткових чисел\n2. Множення звичайних дробів\n3. Вихід\n";
        std::cin >> menu;

        if (menu == 3)
            return 0;

        if (menu == 1) {
            std::cout << "Введіть два десяткових числа: ";
            std::cin >> num1 >> num2;
            std::cout << "Результат множення: " << multiplyDecimals(num1, num2) << std::endl;
        } else if (menu == 2) {
            std::cout << "Введіть чисельник і знаменник першої дроби через пробіл: ";
            std::cin >> numerator1 >> denominator1;
            std::cout << "Введіть чисельник і знаменник другої дроби через пробіл: ";
            std::cin >> numerator2 >> denominator2;
            
            if (denominator1 == 0 || denominator2 == 0) {
                std::cout << "Ділення на нуль неможливе.\n";
                continue;
            }

            int resultNumerator, resultDenominator;
            multiplyFractions(numerator1, denominator1, numerator2, denominator2, resultNumerator, resultDenominator);
            std::cout << "Результат множення дробів: " << resultNumerator << "/" << resultDenominator << std::endl;
        }
    } while (true);

    return 0;
}
