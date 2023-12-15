#include<iostream>
#include<cmath>
using namespace std;

double GetSum(int n)
{
    double sum = 0;
    if(n == 0)
    {
        return sum;
    }
    sum = pow(n, 2)*exp(-sqrt(n));
    n--;
    return sum + GetSum(n);
}

int main()
{
    const int n = 7;
    cout << "Sum of " << n << " elements is: " << GetSum(n);
}
