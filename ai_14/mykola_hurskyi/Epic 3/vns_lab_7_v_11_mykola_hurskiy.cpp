#include <iostream>
#include <cstdarg>

using namespace std;

double sum(int numFractions, ...);
double multiply_decimals(double decimal1, double decimal2);
void multiply_fractions(int numerator1, int denominator1, int numerator2, int denominator2, int& result_numerator, int& result_denominator);

int main() {
    double result1 = sum(5, 0.5, 1.0/3, 0.25, 0.2, 1.0/6);
    double result2 = sum(10, 2.0/3, 1.0/7, 0.75, 5.0/6, 1.0/8, 0.4, 3.0/7, 4.0/9, 0.625, 5.0/8);
    double result3 = sum(12, 0.5, 0.75, 5.0/6, 0.875, 0.9, 11.0/12, 13.0/14, 15.0/16, 17.0/18, 0.95, 21.0/22);
    double result_of_multiplying = multiply_decimals(2.5, 3.5);
    int numerator1 = 1, denominator1 = 2, numerator2 = 3, denominator2 = 4;
    int result_numerator, result_denominator;
    multiply_fractions(numerator1, denominator1, numerator2, denominator2, result_numerator, result_denominator);


    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    cout << result_of_multiplying << endl;
    cout << result_numerator << result_denominator << endl;
    return 0;
}

double sum(int numFractions, ...){
    va_list args;
    va_start(args, numFractions);

    double result = 0.0;

    for (int i = 0; i < numFractions; ++i) {
        double currentFraction = va_arg(args, double);
        result += currentFraction;
    }

    va_end(args);

    return result;
}
double multiply_decimals(double decimal1, double decimal2) {
    double result_of_multiplying = decimal1 * decimal2;
    return result_of_multiplying;
}
void multiply_fractions(int numerator1, int denominator1, int numerator2, int denominator2, int& result_numerator, int& result_denominator) {
    result_numerator = numerator1 * numerator2;
    result_denominator = denominator1 * denominator2;
}