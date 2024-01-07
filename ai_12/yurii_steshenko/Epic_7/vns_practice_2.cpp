#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    cout << "Enter x: ";
    cin >> x;

    double y = 0;
    for (int i = 1; i <= 10; ++i)
        y += pow(x, i) / i;
    cout << y;
    return 0;
}