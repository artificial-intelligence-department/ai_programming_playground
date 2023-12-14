#include <iostream>

// Вимога 15 - в коді використано рекурсивну функцію.
int factorial(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;
    // Вимога 21 - в коді використано оператори виведення та виведення даних.
    std::cout << "Type a number , you want to calculate factorial: " << std::endl;
    std::cin >> n;
    std::cout << "Factorial of " << n << " is: " << factorial(n) << std::endl;

    return 0;
}