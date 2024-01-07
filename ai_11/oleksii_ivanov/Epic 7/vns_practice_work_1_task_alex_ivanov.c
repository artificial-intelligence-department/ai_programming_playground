#include <stdio.h>
#include <math.h>

// Calculate the value by formula
//          z^2
// ---------------------
//      3 + z^2 / 5
double calculateB(double z) {
    double numerator = pow(z, 2);
    double denominator = 3 + numerator / 5.0;
    return 1 + numerator / denominator;
}

//          2 * cos(x - pi/6) * B
//        -------------------------
//              0.5 + sin^2(y)
double calculateA(double x, double y, double z) {
    double numerator = 2 * cos(x - M_PI / 6.0) * calculateB(z);
    double denominator = 0.5 + pow(sin(y), 2);
    return numerator / denominator;
}

int main() {
    // Projected A: 2.82355
    // Projected B: 3,24771 (354/109)

    // constant variables are calculated during runtime
    // and disallow to change their values
    const double x = 1.45, y = -1.22, z = 3.5;

    // calculate the result
    const double    a = calculateA(x, y, z),
                    b = calculateB(z);

    // print the result
    printf("A: %lf\nB: %lf\n", a, b);
    return 0;
}
