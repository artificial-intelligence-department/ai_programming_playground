#include<bits/stdc++.h> 
using namespace std;

int main() {
    double xmin = 0.5;
    double xmax = 3.1;
    double xstep = 0.2;

    double astart = 0.1;
    double step = 0.3;

    for (double x = xmin, a = astart; x <= xmax; x += xstep, a += step) {
        double y;

        if (x > 2) {
            y = cos(a * x + 2);
        } else {
            y = tan(fabs(x - 2 * a));
        }

        cout << "a = " << a << ", x = " << x << ", y = " << y << endl;
    }

    return 0;
}
