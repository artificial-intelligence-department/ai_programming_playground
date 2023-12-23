#include <stdio.h>
#include <math.h>
#include <fcntl.h>  // _setmode and _O_U8TEXT

// set UTF-8 mode to print Ukrainian characters
void set_utf8() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

// calculate triangle area by two sides and angle between them
double area(double a, double b, double angle_degrees) {
    return 0.5 * a * b * sin(angle_degrees * M_PI / 180);
}

int main() {
    set_utf8();

    double a, b, angle;

    // read input

    wprintf(L"Введіть (через пропуск) довжини двох сторін (см) трикутника: ");
    wscanf(L"%lf %lf", &a, &b);

    wprintf(L"Введіть величину кута між сторонами трикутника (градуси): ");
    wscanf(L"%lf", &angle);

    // calculate and print result
    wprintf(L"Площа трикутника: %.2lf (см^2)\n", area(a, b, angle));

    return 0;
}
