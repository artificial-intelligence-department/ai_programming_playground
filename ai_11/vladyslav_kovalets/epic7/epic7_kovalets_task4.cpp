#include <iostream>

// 15. в коді використано рекурсивну функцію
unsigned long long factorial(int n) 
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// 12. в коді використано перевантаження функції 
unsigned long long factorial(long long n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() 
{
    // 16. в коді використано параметри та аргументи функції
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    unsigned long long factorials = factorial(num);

    std::cout << "Factorial = " << factorials;

}
