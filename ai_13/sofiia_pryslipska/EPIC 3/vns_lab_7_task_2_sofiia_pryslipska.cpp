#include <iostream>
using namespace std;

// Перевантажена функція для множення десяткових дробів
float multiply(float a, float b)
{
    return a * b;
}

// Перевантажена функція для множення звичайних дробів
float multiply(int num1, int den1, int num2, int den2)
{
    return (num1 * num2) / (den1 * den2);
}

int main()
{
    //  множення десяткових дробів
    float result1 = multiply(3.5, 2.0);
    cout << "Result of multiplying decimals: " << result1 << endl;

    // множення звичайних дробів

    float result2 = multiply(5, 10, 20, 10);
    cout << "Result of multiplying fractions: " << result2 << endl;

    return 0;
}