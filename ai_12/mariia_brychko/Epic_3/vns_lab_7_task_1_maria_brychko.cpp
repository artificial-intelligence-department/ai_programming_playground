#include <iostream>
#include <cstdarg>
using namespace std;

int minim(int k, ...) {
va_list par;
va_start(par, k);
int min = va_arg(par, int);

for (int i = 1; i < k; i++) {
        int temp = va_arg(par, int);
        if (temp < min) {
            min = temp;
        }
    }

va_end(par);
return min;
}

double minim(double k, ...) {
va_list par;
va_start(par, k);
double min = va_arg(par, double);

for (int i = 1; i < k; i++) {
        double temp = va_arg(par, double);
        if (temp < min) {
            min = temp;
        }
    }

va_end(par);
return min;
}



int main () {
    cout << "Minimum of 5 ints: " << minim (5, 26, 65, 13, 78, 4) << endl;
    cout << "Minimum of 10 ints: " << minim (10, 47, 48, 90, 20, 52, 26, 65, 13, 78, 2) << endl;
    cout << "Minimum of 12 ints: " << minim (12, 47, 48, 90, 20, 52, 26, 65, 13, 78, 9, 42, 55) << endl;

    cout << "Minimum of 5 doubles: " << minim (5.0, 26.5, 65.8, 13.39, 78.15, 4.25) << endl;
    cout << "Minimum of 10 doubles: " << minim (10.0, 47.45, 48.98, 90.12, 20.346, 52.653, 26.7654, 65.347, 13.12, 78.45, 2.67) << endl;
    cout << "Minimum of 12 doubles: " << minim (12.0, 47.97, 48.45, 90.78, 20.234, 52.72, 26.4, 65.56, 13.16, 78.87, 9.568, 42.25, 55.98) << endl;

    return 0;
}
