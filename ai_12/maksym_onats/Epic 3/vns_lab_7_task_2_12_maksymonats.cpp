#include <iostream>
using namespace std;

double divide(double x, double y) {
    return x / y;
}

float divide(float x, float y) {
    return x / y;
}

int main() {
    double a = 10.5, b = 2.5;
    cout << "Result of dividing decimals: " << divide(a, b) << endl;

    float c = 10.5f, d = 2.5f;
    cout << "Result of dividing fractions: " << divide(c, d) << endl;

    return 0;
}