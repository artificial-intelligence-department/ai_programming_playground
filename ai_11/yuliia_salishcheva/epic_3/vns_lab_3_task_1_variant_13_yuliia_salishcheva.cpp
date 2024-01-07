#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double epsilon, a, b, x, k, n, an, sn, y, se;
    n = 10;
    y = 0;
    epsilon = 0.0001;
    x = 0.2;
    a = 0.2;
    b = 1;
    k = 10;
    se = 0;
    sn = 0;
    for (double x = 0.2; x <= 1; x += 0.1) {

        double value;

        y = (1.0 / 2) * log(x);

        for (int i = 0; i < n; i++) {
            sn += 1.0 / (2 * i + 1) * pow(((x - 1) / (x + 1)), 2 * i + 1);

        }

        int i = 0;
        an = 1.0 / (2 * i + 1) * pow(((x - 1) / (x + 1)), 2 * i + 1);

        while (abs(an) > epsilon) {
            an = 1.0 / (2 * i + 1) * pow(((x - 1) / (x + 1)), 2 * i + 1);
            se += an;
            i++;
        }

        cout << "X= " << x << "  SN= " << sn << "  SE= " << se << "  Y= " << y << endl;
        se = 0;
        sn = 0;
    }

}