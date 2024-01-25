// 20
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double step = 0.5,
                 end = 4.0,
                 epsilon = 0.0001;

    double x = -4.0;

    cout << "x\t\ty\n";
    while (x <= end + epsilon)
    {
        cout << x << "\t\t" << abs(x - 2) + abs(x + 1) << endl;
        x += step;
    }

    return 0;
}
