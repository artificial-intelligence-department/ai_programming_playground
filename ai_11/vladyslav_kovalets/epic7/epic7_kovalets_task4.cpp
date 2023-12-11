#include <iostream>

int main()
{
    unsigned long long factorials = 1;
    int factorial;
    std::cout << "Enter number ";
    std::cin >>factorial;

    for(int i=1; i<=factorial; i++)
    {
        factorials *= i;
    }

    std::cout << "Factorial = " << factorials;
}