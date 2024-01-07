#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;

double triangle(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double square(double n1, double n2, double n3)
{
    return triangle(n1,n2,n3);
}

double square(int n, ...) 
{
    double result = 0;
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; ++i) {
        result += va_arg(args, int);
    }

    double p = result / 2;
    double product = 1;

    va_end(args);
    va_start(args, n);

    for (int i = 0; i < n; ++i) {
        double side = va_arg(args, double);
        product *= (p - side);
    }

    va_end(args);

    return sqrt(product * result);
}

int main() {
    double AreaResult = triangle(5, 12, 8);
    cout<< "Triangle area (using triangle function): " <<AreaResult<<endl;

    AreaResult = square(3, 5, 12, 8);
    cout<< "Triangle area (using square function): " <<AreaResult<<endl;

    AreaResult = square(5, 1, 2, 3, 4, 5);
    cout<< "Pentagon area: " <<AreaResult<<endl;

    AreaResult = square(8, 1, 2, 3, 4, 5, 6, 7, 8);
    cout<< "Octagon area: " <<AreaResult<<endl;

    return 0;
}
