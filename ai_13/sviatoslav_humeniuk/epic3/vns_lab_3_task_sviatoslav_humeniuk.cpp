#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double SN(double x) {
    double sum = 0;
    double diff = x * x / 2;
    
    for (int i = 2; i <= 20; i += 2) {
        sum += diff;
        diff *= -x * x / (i * (i + 1));
    }

    return sum;
}

double SE(double x, double eps) {
    double sum = 0;
    double diff = x * x / 2;
    int i = 2;

    while (fabs(diff) > eps) {
        sum += diff;
        diff *= -x * x / (i * (i + 1));
        i += 2;
    }

    return sum;
}


double y(double x) {
    return x * atan(x) - log(pow(x * x + 1, 0.5));
}

int main() {
    double eps = 0.0001;

    for (double x = 0.1; x <= 0.8; x += 0.1) {
        cout << "x = " << x;
        cout << " sn = " << SN(x);
        cout << " se = " << fixed << setprecision(4) << SE(x, eps);
        cout.unsetf(ios_base::floatfield);
        cout << " y = " << y(x) << endl;
    }

    return 0;
}
