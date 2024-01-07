#include <iostream>
#include <cmath>

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    double sum = 0.0000, precision = 0.0001;
    double term;
    double numer = factorial(1), denom = 3 * std::pow(1, 1);
    term = numer / denom;
    sum += term;
    for (int n = 2; std::abs(term) >= precision; n++)
    {
        numer = factorial(n);
        denom = 3 * std::pow(n, n);
        term = numer / denom;
        sum += term;
    }
    std::cout << "The sum of this series is: " << sum;
}