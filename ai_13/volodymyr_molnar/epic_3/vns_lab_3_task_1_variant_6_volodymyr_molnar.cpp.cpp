#include <iostream>
#include <cmath>
using namespace std;

int fact(int a) {
    int factorial = 1;
    for (int i = 1; i <= a; i++)
        factorial *= i;
    return factorial;
}

double calculateSum(double x, int n) {
    double sum = 1.0;
    double angle = 3.1415 / 4.0;

    for (int i = 1; i <= n; ++i) {
        double term = cos(i * angle) / fact(i) * pow(x, i);
        sum += term;
    }

    return sum;
}
int main() {
    int n = 25;
    double step = 0.1; 
    double e = exp(1.0);
    double angle_rad1 = 3.1415 / 4; 
    double angle_rad2 = sin(angle_rad1);
    double x{ 0.1 };
    while (x <= 1) {
        double y = (pow(e, x * cos(angle_rad1)) ) * cos(x * angle_rad2);
        cout << "x = " << x << ", y = " << y << endl;
        x += 0.1;

    }
    cout << "\n\n";


    for (double x = 0.1; x <= 1; x += step) {
        cout << calculateSum(x, n) << endl;
    }
    return 0;

}
