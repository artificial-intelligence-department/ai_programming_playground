#include <iostream>
#include <math.h>
using namespace std;
int factorial(int a)
{
    
    if (a > 0)
    {
        int x = 1;
        for (int i = 1; i <= a; i++)
        {
            x = x * i;
        }
        return x;
    }
    if (a == 0)
        {
            return 1;
        }
}

int main()
{
    double sum = 0;
    for (int n = 1; n <= 10; n++)
    {
        double x = factorial(n) / (pow(n, sqrt(n)));
        sum = sum + x;
       
    }
    cout << "The sum is " << sum;
}