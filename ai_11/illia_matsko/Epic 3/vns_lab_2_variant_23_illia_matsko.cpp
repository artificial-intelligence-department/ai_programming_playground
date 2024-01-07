#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 10;
    double result = 0;
    while(n>0)
    {
        result += tgamma(n) / pow(n, sqrt(n));
        n--;
    }

    cout << "Result = " << result;
}