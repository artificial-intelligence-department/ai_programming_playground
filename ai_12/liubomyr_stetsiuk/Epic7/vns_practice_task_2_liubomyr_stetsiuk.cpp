#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int b = 2;
    long double y;
    bool stop = false;

    for (double x = 1; x <= 3; x += 0.1)
    {
        for (int a = 1; a <= 5; a += 1)
        {
            if (x < b)
            {
                y = sin(abs(a * x + pow(b, a)));
                cout << "y = " << y << endl;
            }
            if (x >= b)
            {
                y = cos(abs(a * x - pow(b, a)));
                cout << "y = " << y << endl;
            }
        }
    }

    return 0;
}
