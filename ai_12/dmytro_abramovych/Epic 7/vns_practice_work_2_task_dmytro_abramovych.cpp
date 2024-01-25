// 6
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double step = 0.5, a = 5.3, a_squared = pow(a, 2);
    double x = -3;

    while (x <= 3)
    {
        cout << "x: " << x << " y: "
        // y == 1.1; 1.1^2 == 1.21
             << (pow(x, 2) + 1.21 <= a_squared
                     ? x / (15 * pow(x, 2))
                     : pow(x, 2) / exp(x))
             << "\n";

        x += step;
    }

    return 0;
}
