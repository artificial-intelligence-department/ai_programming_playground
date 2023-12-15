#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

int powerOrSqrt(int number, int n)
{
    number = pow(number, n);
    return number;
}
double powerOrSqrt(int n, double number)
{
    number = pow(number, 1.0 / n);
    return number;
}

int main()
{

    cout << "2^5 = " << powerOrSqrt(2, 5) << endl;
    cout << "8^4 = " << powerOrSqrt(8, 4) << endl;
    cout << "4 \u221A 126.23 = " << powerOrSqrt(4, 126.23) << endl;
    cout << "8 \u221A 126472.123 = " << powerOrSqrt(8, 126472.123) << endl;
}