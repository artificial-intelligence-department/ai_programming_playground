#include <iostream>

// Функція для обчислення добутку десяткових дробів
float computeProduct(float num1, float num2)
{
    return num1 * num2;
}

// Функція для обчислення добутку звичайних дробів
float computeProduct(int numerator1, int denominator1, int numerator2, int denominator2)
{
    return (numerator1 * numerator2) / (float)(denominator1 * denominator2);
}

int main()
{
    // Обчислення добутку десяткових дробів
    float product1 = computeProduct(3.5, 2.0);
    std::cout << "Product of decimals: " << product1 << std::endl;

    // Обчислення добутку звичайних дробів
    float product2 = computeProduct(5, 10, 20, 10);
    std::cout << "Product of fractions: " << product2 << std::endl;

    return 0;
}
