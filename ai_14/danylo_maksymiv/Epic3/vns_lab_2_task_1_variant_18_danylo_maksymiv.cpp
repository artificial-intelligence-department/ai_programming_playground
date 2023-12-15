#include<iostream>
#include<cmath>
using namespace std;

long factorial(int n) 
{
    if (n == 0 || n == 1) 
    {
        return 1;
    } 
    else 
    {
        return n * factorial(n - 1);
    }
}

int main() {
    double eps = 0.0001, fraction, sum = 0.0;
    int n = 1;

    do 
    {
        fraction = pow(n, 3) / factorial(3 * n - 3);
        sum += fraction;
        n++;
        cout << sum << endl;
    } while (fraction > eps);


    return 0;
}
