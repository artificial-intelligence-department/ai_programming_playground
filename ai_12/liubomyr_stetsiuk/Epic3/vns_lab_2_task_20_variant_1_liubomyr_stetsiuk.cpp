
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double epsilon = 0.0001;
    double sum = 0.0;
    double term = 1.0;

    int n = 0;
    while (abs(term) >= epsilon)
    {
        sum += term;
        n++;
        term = exp(n) * pow(100, -n * n);
    }

    cout << "Sum of the series is: " << sum << endl;

    return 0;
}
