#include <iostream>
#include <cmath>

int main() {
    double a = (5.0/6), sum = a, e = 0.0001, n = 1;
    while (a>=e) {
        a = a * (  (pow(3,n+1) + pow(2,n+1))  /  (2*pow(3,n+1) + 3*pow(2,n+1))  );
        sum += a;
        ++n;
    }
    printf("%.4f", sum);
    return 0;
}