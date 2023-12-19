#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(3, x);
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 10;
    double eps = 0.0001;

    
    for (double x = 0.1; x <= 1.0; x += 0.1) {
        double sum = 0;

        
        for (int i = 0; i <= n; i++) {
            sum += pow(x, i) / factorial(i);
        }

        double exact = f(x);

        
        cout << setprecision(6) << fixed;
        cout << "x = " << x << endl;
        cout << "n = " << n << endl;
        cout << "Sum = " << sum << endl;
        cout << "Exact = " << exact << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}
