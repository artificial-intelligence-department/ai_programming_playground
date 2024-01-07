// ВАРІАНТ 16

#include <iostream>
#include <cmath>
using namespace std;
int math(double a, double b)
{
    float c = (pow((a-b),3) - (pow(a,3) - 3*a*a*b)) / (pow(b,3) - 3*a*b*b);
    return c;
}
int main()
{
    double a, b, c;
    a = 1000;
    b = 0.0001;
    c = math(a,b);
    printf("c = %.1f\n", c);
    return 0;
}
