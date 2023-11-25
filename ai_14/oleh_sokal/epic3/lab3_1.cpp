#include <iostream>
#include <cmath>

double periodOfN(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * periodOfN(n - 1);
    }
}

int main() {

    double e = exp(1.0);  
    double x = 0.1;
    double sn, se, y;
    double accuracy = 0.0001;

    for (double i = x; i <= 1; i += 0.1) {
        sn = 1;
        double sen = 0;
        for (int n = 1; n <= 20; n++) {
            sn += pow(2 * i, n) / periodOfN(n);
        }

       int n = 0;
        while (accuracy < (pow(2 * i, n) / periodOfN(n))) {
            se = 0.0;
            se = pow(2 * i, n) / periodOfN(n);
            sen +=se;
            n++;
        }
            y= pow(e, 2*x);
 std::cout << "X:\t " << x << " SN:\t " << sn << " SE:\t " << sen << " Y:\t " << y << "\n";
    x += 0.1;
    }
    

    return 0;
}