#include <iostream>
using namespace std;

int main()
{
    double s = 0.0, z = 0.0, x = 1.2, y = -0.8;
    s = 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 4;
    z = (sin(pow(x, 3) + pow(cos(y), 2)));
    cout << s << endl;
    cout << z << endl;
}

