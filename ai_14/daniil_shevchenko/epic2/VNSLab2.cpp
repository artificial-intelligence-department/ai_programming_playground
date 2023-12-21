#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double sum = 0;
    double x = 1;
    for (int i = 0; i < 10; i++)
    {
        double a = (i+1) * pow(i, sqrt(i));
        double b = pow((i + 1), sqrt(i + 1));
        double c = a / b;
        x = x * c;
        sum = sum + x;
    }
    cout << "The sum is " << sum;
}
