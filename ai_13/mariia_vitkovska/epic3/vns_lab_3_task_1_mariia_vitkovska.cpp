#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x_step = 0.19, epsilon = 0.0001, x = -2, factorial = 1;
    long double result = 0, y = 0, j = 1, SN = 0, result1;

    while (x <= -0.1) {
        y = log(1 / (2 + 2 * x + pow(x, 2)));
        SN = 0;
        j = 1;
        result = 0;

        for (int i = 1; i <= 40; i++) {
            for (int k = 1; k <= 2 * i; k++) {
                factorial *= k;
            }
            SN += (pow((-1), i) * (pow(2 * x, 2 * i) / factorial));
            factorial = 1;
        }

        do {
            for (int k = 1; k <= 2 * j; k++) {
                factorial *= k;
            }
            result1 = result;
            result += (pow((-1), j) * (pow(2 * x, 2 * j) / factorial));
            j++;
            factorial = 1;
        } while (abs(result - result1) > epsilon);

        cout << "x = " << x << "   " << "SN = " << SN << "   " << "SE = " << result << "   " << "Y = " << y << endl;
        x += x_step;
    }

    return 0;
}
