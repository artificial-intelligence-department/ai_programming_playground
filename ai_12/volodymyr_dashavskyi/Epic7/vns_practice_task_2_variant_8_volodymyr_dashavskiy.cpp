#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    double x;
    double z, y;
    // Вимога 10 цикл for
    for (x = 1; x <= 4; x += 0.5)
    {

        z = abs(x) + pow(x, 3);
        y = z * ((sin(pow(2 + x, 2))) / (2 + x));
        cout << fixed << setprecision(3) << "Z: " << z << "\tY: " << y << endl;
        if (x == 4)
        {
            // Вимога 11 оператор break
            break;
        }
    }
    return 0;
}