#include <iostream>
#include <math.h>
using namespace std;

double countSum(long n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        double expression = pow(-1, n - 1) / pow(n, n);
        return countSum(n - 1) + expression;
    }
}

int main()
{
    long n = 10;
    cout << "Sum is: " << countSum(n);
    return 0;
}