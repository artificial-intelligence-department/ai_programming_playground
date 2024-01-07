#include <iostream>
#include <cmath>
using namespace std;
int fact(int n)
{

    if (n == 1)
    {

        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    double num = 10;
    double sum = 0;
    for (int n = 1; n <= num; n++)
    {

        sum = (fact(n)) / (pow(n, sqrt(n)));
    }
    cout << "The sum is" << endl
         << sum;
    return 0;
}
