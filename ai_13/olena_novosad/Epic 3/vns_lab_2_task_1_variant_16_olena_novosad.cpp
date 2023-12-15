#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{

    double An;
    int n = 1;
    double A1 = log10(factorial(n)) * exp((-n) * pow(n, 0.5));
    n = 2;
    double A2 = log10(factorial(n)) * exp((-n) * pow(n, 0.5));
    double sum = A1 + A2;
    double eps = 0.0001;
    double prevA = A2;

    do
    {

        An = prevA * ((log10(factorial(n + 1))) * exp(-(n + 1) * (pow((n + 1), 0.5)))) / ((log10(factorial(n))) * exp(-n * pow(n, 0.5))); // використали n+1 і n+2 для уникнення ділення на 0
        prevA = An;
        sum += An;
        n++;
    } while (abs(An) > eps);

    cout << sum;

    return 0;
}